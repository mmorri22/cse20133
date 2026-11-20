#include "matmul.h"

#include <math.h>
#include <time.h>
#include <cblas.h>

/* ---- Provided for you ---- */

double now_seconds(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec * 1.0e-9;
}

void fill_matrix(double *mat, int m, uint32_t seed)
{
	for (int i = 0; i < m * m; i++) {
		seed = seed * 1664525U + 1013904223U;	/* a simple pseudo-random generator */
		mat[i] = (double)seed / 2147483648.0 - 1.0;
	}
}

void zero_matrix(double *mat, int m)
{
	for (int i = 0; i < m * m; i++) {
		mat[i] = 0.0;
	}
}

double max_abs_diff(const double *x, const double *y, int m)
{
	double max_diff = 0.0;
	for (int i = 0; i < m * m; i++) {
		double diff = fabs(x[i] - y[i]);
		if (diff > max_diff) {
			max_diff = diff;
		}
	}
	return max_diff;
}

/* ---- You will write these ---- */

/* Part 2 - Return GFLOP/s for one m x m multiply that took the given seconds */
double gflops(int m, double seconds)
{
	/* Delete these lines and write your code */
	(void)m; (void)seconds;
	return 0.0;
}

/* Part 2 - Your i-j-k loop from In-Class Lecture 33, now for any size m */
void matmul_ijk(const double *a, const double *b, double *c, int m)
{
	/* Delete this line and write your code */
	(void)a; (void)b; (void)c; (void)m;
}

/* Part 2 - Your i-k-j loop from In-Class Lecture 33, now for any size m */
void matmul_ikj(const double *a, const double *b, double *c, int m)
{
	/* Delete this line and write your code */
	(void)a; (void)b; (void)c; (void)m;
}

/* Part 2 - One call to cblas_dgemm */
void matmul_blas(const double *a, const double *b, double *c, int m)
{
	/* Delete this line and write your code */
	(void)a; (void)b; (void)c; (void)m;
}

/* Part 2 - Sort times[] in place, then return the median of the n values */
double median(double times[], int n)
{
	/* Delete these lines and write your code */
	(void)times; (void)n;
	return 0.0;
}
