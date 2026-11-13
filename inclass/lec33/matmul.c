/*
 * In-Class Lecture 33 - How Far Is a Hand-Written Loop from BLAS?
 *
 * We compute C = A x B for two M x M matrices of doubles three ways:
 *   1. The textbook i-j-k loop
 *   2. The same arithmetic in i-k-j order
 *   3. BLAS cblas_dgemm
 *
 * Every version must produce the same answer to within a tolerance,
 * and we time each one.
 */

/* clock_gettime is part of POSIX, not ISO C, so -std=c2x hides it unless we ask */
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <cblas.h>

#define M 512
#define TOLERANCE 1.0e-9

/* Seconds from a clock that only moves forward */
double now_seconds(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec * 1.0e-9;
}

/* Fill a matrix with repeatable values between -1.0 and 1.0 */
void fill_matrix(double *mat, uint32_t seed)
{
	for (int i = 0; i < M * M; i++) {
		seed = seed * 1664525U + 1013904223U;	/* a simple pseudo-random generator */
		mat[i] = (double)seed / 2147483648.0 - 1.0;
	}
}

/* Set every element of a matrix to 0.0 */
void zero_matrix(double *mat)
{
	for (int i = 0; i < M * M; i++) {
		mat[i] = 0.0;
	}
}

/* Largest absolute difference between two matrices */
double max_abs_diff(const double *x, const double *y)
{
	double max_diff = 0.0;
	for (int i = 0; i < M * M; i++) {
		double diff = fabs(x[i] - y[i]);
		if (diff > max_diff) {
			max_diff = diff;
		}
	}
	return max_diff;
}

/* Billions of floating-point operations per second for one M x M multiply */
double gflops(double seconds)
{
	return 2.0 * (double)M * (double)M * (double)M / (seconds * 1.0e9);
}

/* Step 1 - The textbook triple loop, i-j-k order */
void matmul_ijk(const double *a, const double *b, double *c)
{
	/* Delete this line once you write the loops */
	(void)a; (void)b; (void)c;

}

/* Step 3 - The same arithmetic, i-k-j order */
void matmul_ikj(const double *a, const double *b, double *c)
{
	/* Delete this line once you write the loops */
	(void)a; (void)b; (void)c;

}

int main(void)
{
	size_t bytes = (size_t)M * M * sizeof(double);
	double *a = (double *)malloc(bytes);
	double *b = (double *)malloc(bytes);
	double *c_ijk = (double *)malloc(bytes);
	double *c_ikj = (double *)malloc(bytes);
	double *c_blas = (double *)malloc(bytes);

	if (a == NULL || b == NULL || c_ijk == NULL || c_ikj == NULL || c_blas == NULL) {
		fprintf(stderr, "Allocation failed\n");
		free(a); free(b); free(c_ijk); free(c_ikj); free(c_blas);
		return EXIT_FAILURE;
	}

	fill_matrix(a, 1U);
	fill_matrix(b, 2U);
	zero_matrix(c_ijk);
	zero_matrix(c_ikj);
	zero_matrix(c_blas);

	fprintf(stdout, "Multiplying two %d x %d matrices\n\n", M, M);

	/* Step 2 - Time matmul_ijk and print its time and GFLOP/s */


	/* Step 4 - Time matmul_ikj, print its time and GFLOP/s, and its
	 *          maximum difference from the i-j-k result */


	/* Step 5 - Time cblas_dgemm, print its time and GFLOP/s, and its
	 *          maximum difference from the i-j-k result */


	/* Step 6 - Print PASS or FAIL for each comparison using TOLERANCE */


	free(a);
	free(b);
	free(c_ijk);
	free(c_ikj);
	free(c_blas);
	return EXIT_SUCCESS;
}
