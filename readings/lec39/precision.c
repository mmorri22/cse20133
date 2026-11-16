#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/*
 * One kernel, four engines. y = A x, a matrix times a vector (GEMM with a
 * single column), computed the way four different processors would:
 *   FP64  - the reference, as on a CPU
 *   FP32  - single precision, as on many GPUs
 *   Q15   - 16-bit fixed point, as on a DSP
 *   INT8  - 8-bit integers with a scale factor, as on an NPU
 */
#define N 16

static double A[N][N];
static double x[N];
static double y_ref[N];

static uint32_t rng_state = 39U;

/* Repeatable values between -1.0 and 1.0 */
double rand_signed(void)
{
	rng_state = rng_state * 1664525U + 1013904223U;
	return (double)(rng_state >> 8) / 8388608.0 - 1.0;
}

/* ---- FP64: the reference ---- */
void mv_fp64(double y[N])
{
	for (int i = 0; i < N; i++) {
		double sum = 0.0;
		for (int j = 0; j < N; j++) {
			sum += A[i][j] * x[j];
		}
		y[i] = sum;
	}
}

/* ---- FP32: the same loop in single precision ---- */
void mv_fp32(double y[N])
{
	for (int i = 0; i < N; i++) {
		float sum = 0.0f;
		for (int j = 0; j < N; j++) {
			sum += (float)A[i][j] * (float)x[j];
		}
		y[i] = (double)sum;
	}
}

/* ---- Q15: 16-bit fixed point. A value v in [-1, 1) is stored as v * 32768 ---- */
int16_t to_q15(double v)
{
	double scaled = round(v * 32768.0);
	if (scaled > 32767.0) {
		return INT16_MAX;	/* saturate instead of wrapping */
	}
	if (scaled < -32768.0) {
		return INT16_MIN;
	}
	return (int16_t)scaled;
}

void mv_q15(double y[N])
{
	for (int i = 0; i < N; i++) {
		int64_t acc = 0;	/* a wide accumulator, as DSPs provide */
		for (int j = 0; j < N; j++) {
			acc += (int32_t)to_q15(A[i][j]) * (int32_t)to_q15(x[j]);
		}
		/* Each product has 30 fraction bits; shift back to Q15 and saturate */
		int64_t q = acc >> 15;
		if (q > INT16_MAX) {
			q = INT16_MAX;
		}
		if (q < INT16_MIN) {
			q = INT16_MIN;
		}
		y[i] = (double)q / 32768.0;
	}
}

/* ---- INT8: each array gets one scale factor, values become -127 to 127 ---- */
double max_abs(const double *v, int count)
{
	double m = 0.0;
	for (int i = 0; i < count; i++) {
		if (fabs(v[i]) > m) {
			m = fabs(v[i]);
		}
	}
	return m;
}

void mv_int8(double y[N])
{
	double scale_a = max_abs(&A[0][0], N * N) / 127.0;
	double scale_x = max_abs(x, N) / 127.0;

	for (int i = 0; i < N; i++) {
		int32_t acc = 0;
		for (int j = 0; j < N; j++) {
			int8_t qa = (int8_t)lround(A[i][j] / scale_a);
			int8_t qx = (int8_t)lround(x[j] / scale_x);
			acc += (int32_t)qa * (int32_t)qx;
		}
		y[i] = (double)acc * scale_a * scale_x;
	}
}

/* Validate one engine against the reference with a stated tolerance */
void validate(const char *name, const double y[N], double tolerance)
{
	double max_err = 0.0;
	for (int i = 0; i < N; i++) {
		double err = fabs(y[i] - y_ref[i]);
		if (err > max_err) {
			max_err = err;
		}
	}
	fprintf(stdout, "%-6s %12.3e %12.1e   %s\n", name, max_err, tolerance,
		(max_err <= tolerance) ? "PASS" : "FAIL");
}

/* What happens when a Q15 sum does not fit? Sixteen products of 0.9 * 0.9
 * add up to 12.96, far outside the Q15 range of -1 to 1. */
void q15_overflow_demo(void)
{
	const int16_t q = to_q15(0.9);
	int16_t narrow = 0;	/* a 16-bit accumulator that wraps */
	int64_t wide = 0;	/* a wide accumulator, then saturate */

	for (int j = 0; j < N; j++) {
		int32_t product = ((int32_t)q * (int32_t)q) >> 15;
		narrow = (int16_t)(narrow + product);
		wide += product;
	}
	int64_t saturated = (wide > INT16_MAX) ? INT16_MAX : wide;

	fprintf(stdout, "\nSixteen products of 0.9 * 0.9 (true sum 12.96):\n");
	fprintf(stdout, "  16-bit accumulator, wraps:   %9.5f\n", (double)narrow / 32768.0);
	fprintf(stdout, "  wide accumulator, saturates: %9.5f\n", (double)saturated / 32768.0);
}

int main(void)
{
	/* Entries are scaled by 1/N so every result fits in [-1, 1) for Q15 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = rand_signed() / N;
		}
		x[i] = rand_signed();
	}

	double y[N];
	mv_fp64(y_ref);

	fprintf(stdout, "y[0] from each engine:\n");
	fprintf(stdout, "  FP64 %.12f\n", y_ref[0]);
	mv_fp32(y);
	fprintf(stdout, "  FP32 %.12f\n", y[0]);
	mv_q15(y);
	fprintf(stdout, "  Q15  %.12f\n", y[0]);
	mv_int8(y);
	fprintf(stdout, "  INT8 %.12f\n\n", y[0]);

	fprintf(stdout, "%-6s %12s %12s\n", "engine", "max error", "tolerance");
	mv_fp32(y);
	validate("FP32", y, 1.0e-6);
	mv_q15(y);
	validate("Q15", y, 1.0e-3);
	mv_int8(y);
	validate("INT8", y, 2.0e-2);

	q15_overflow_demo();
	return EXIT_SUCCESS;
}
