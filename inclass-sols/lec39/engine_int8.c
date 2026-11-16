/* INT8 engine: 8-bit integers with one scale factor per array, as on an NPU.
 *
 * INSTRUCTOR SOLUTION
 */
#include <stdint.h>
#include <math.h>

#include "engine.h"

const char ENGINE_NAME[] = "INT8";

/* 8 bits give steps of about 1/127 = 0.008 for values near 1. Each output
 * sums three products, each rounded in both inputs, so errors of a few steps
 * are expected: we state 0.02, about two and a half steps. */
const double ENGINE_TOLERANCE = 2.0e-2;

static double max_abs(const double *values, int count)
{
	double m = 0.0;
	for (int i = 0; i < count; i++) {
		if (fabs(values[i]) > m) {
			m = fabs(values[i]);
		}
	}
	return m;
}

void rotate(const double R[DIM][DIM], const double v[DIM], double out[DIM])
{
	double scale_r = max_abs(&R[0][0], DIM * DIM) / 127.0;
	double scale_v = max_abs(v, DIM) / 127.0;
	if (scale_r == 0.0 || scale_v == 0.0) {
		for (int i = 0; i < DIM; i++) {
			out[i] = 0.0;	/* a zero matrix or vector rotates to zero */
		}
		return;
	}

	for (int i = 0; i < DIM; i++) {
		int32_t acc = 0;
		for (int j = 0; j < DIM; j++) {
			int8_t qr = (int8_t)lround(R[i][j] / scale_r);
			int8_t qv = (int8_t)lround(v[j] / scale_v);
			acc += (int32_t)qr * (int32_t)qv;
		}
		out[i] = (double)acc * scale_r * scale_v;
	}
}
