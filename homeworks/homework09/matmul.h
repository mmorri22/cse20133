#ifndef MATMUL_H
#define MATMUL_H

/* clock_gettime is part of POSIX, not ISO C, so -std=c2x hides it unless we ask */
#define _POSIX_C_SOURCE 199309L

#include <stdint.h>

/* The sweep: matrix sizes MIN_SIZE to MAX_SIZE in steps of SIZE_STEP.
 * The #ifndef lets the Makefile shrink the sweep for valgrind. */
#ifndef MIN_SIZE
#define MIN_SIZE 100
#endif

#ifndef MAX_SIZE
#define MAX_SIZE 1000
#endif

#ifndef SIZE_STEP
#define SIZE_STEP 100
#endif

/* Number of timed runs per size; we report the median */
#ifndef REPEATS
#define REPEATS 5
#endif

/* Largest allowed difference between any two results */
#define TOLERANCE 1.0e-9

/* ---- Provided for you ---- */

/* Seconds from a clock that only moves forward */
double now_seconds(void);

/* Fill an m x m matrix with repeatable values between -1.0 and 1.0 */
void fill_matrix(double *mat, int m, uint32_t seed);

/* Set every element of an m x m matrix to 0.0 */
void zero_matrix(double *mat, int m);

/* Largest absolute difference between two m x m matrices */
double max_abs_diff(const double *x, const double *y, int m);

/* ---- You will write these ---- */

/* Billions of floating-point operations per second for one m x m multiply */
double gflops(int m, double seconds);

/* C = A x B, textbook i-j-k order. Overwrites c. */
void matmul_ijk(const double *a, const double *b, double *c, int m);

/* C = A x B, i-k-j order. Adds into c, so c must start at zero. */
void matmul_ikj(const double *a, const double *b, double *c, int m);

/* C = A x B using cblas_dgemm. Overwrites c. */
void matmul_blas(const double *a, const double *b, double *c, int m);

/* Sorts times[] in place and returns the median of the n values */
double median(double times[], int n);

#endif
