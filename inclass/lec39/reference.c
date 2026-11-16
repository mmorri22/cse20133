/* The FP64 reference engine. Every other engine is qualified against this one. */
#include "engine.h"

void rotate_reference(const double R[DIM][DIM], const double v[DIM], double out[DIM])
{
	for (int i = 0; i < DIM; i++) {
		double sum = 0.0;
		for (int j = 0; j < DIM; j++) {
			sum += R[i][j] * v[j];
		}
		out[i] = sum;
	}
}
