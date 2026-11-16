/* FP32 engine: single-precision floating point, as on many GPUs.
 * This one is complete. Use it as the model for your own engines. */
#include "engine.h"

const char ENGINE_NAME[] = "FP32";
const double ENGINE_TOLERANCE = 1.0e-6;

void rotate(const double R[DIM][DIM], const double v[DIM], double out[DIM])
{
	for (int i = 0; i < DIM; i++) {
		float sum = 0.0f;
		for (int j = 0; j < DIM; j++) {
			sum += (float)R[i][j] * (float)v[j];
		}
		out[i] = (double)sum;
	}
}
