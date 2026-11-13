/* clock_gettime is part of POSIX, not ISO C, so -std=c2x hides it unless we ask */
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Sum every element of an N x N matrix twice: once row by row, once column
 * by column. Same arithmetic, same answer. Only the ORDER of memory access
 * changes.
 */
#define N 2048
#define REPEATS 5

/* Seconds since an arbitrary fixed point, from a clock that never jumps */
double now_seconds(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec * 1.0e-9;
}

double sum_by_rows(const double *mat)
{
	double sum = 0.0;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			sum += mat[row * N + col];	/* next element is next in memory */
		}
	}
	return sum;
}

double sum_by_cols(const double *mat)
{
	double sum = 0.0;
	for (int col = 0; col < N; col++) {
		for (int row = 0; row < N; row++) {
			sum += mat[row * N + col];	/* next element is N doubles away */
		}
	}
	return sum;
}

int main(void)
{
	double *mat = (double *)malloc((size_t)N * N * sizeof(double));
	if (mat == NULL) {
		fprintf(stderr, "Allocation failed\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < N * N; i++) {
		mat[i] = 1.0;
	}

	for (int rep = 0; rep < REPEATS; rep++) {
		double start = now_seconds();
		double row_sum = sum_by_rows(mat);
		double row_time = now_seconds() - start;

		start = now_seconds();
		double col_sum = sum_by_cols(mat);
		double col_time = now_seconds() - start;

		fprintf(stdout, "Run %d: rows %.4f s (sum %.0f)   cols %.4f s (sum %.0f)   ratio %.1fx\n",
			rep + 1, row_time, row_sum, col_time, col_sum, col_time / row_time);
	}

	free(mat);
	return EXIT_SUCCESS;
}
