#include <stdio.h>
#include <cblas.h>

/*
 * C = alpha * (A x B) + beta * C, using BLAS.
 * With alpha = 1.0 and beta = 0.0, this is an ordinary matrix multiply.
 */
int main(void)
{
	double a[2][2] = { { 1.0, 2.0 }, { 3.0, 4.0 } };
	double b[2][2] = { { 5.0, 6.0 }, { 7.0, 8.0 } };
	double c[2][2] = { { 0.0, 0.0 }, { 0.0, 0.0 } };

	cblas_dgemm(CblasRowMajor,	/* C stores 2D arrays row by row */
		    CblasNoTrans,	/* use A as-is (not transposed) */
		    CblasNoTrans,	/* use B as-is */
		    2, 2, 2,		/* M, N, K: A is MxK, B is KxN, C is MxN */
		    1.0,		/* alpha */
		    &a[0][0], 2,	/* A and its row length */
		    &b[0][0], 2,	/* B and its row length */
		    0.0,		/* beta */
		    &c[0][0], 2);	/* C and its row length */

	fprintf(stdout, "%6.1f %6.1f\n%6.1f %6.1f\n", c[0][0], c[0][1], c[1][0], c[1][1]);
	return 0;
}
