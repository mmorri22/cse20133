/* INT8 engine: 8-bit integers with one scale factor per array, as on an NPU.
 * Time permitting. */
#include <stdint.h>
#include <math.h>

#include "engine.h"

const char ENGINE_NAME[] = "INT8";

/* Step 4: state your tolerance BEFORE you qualify. Justify it in a comment. */
const double ENGINE_TOLERANCE = 0.0;

void rotate(const double R[DIM][DIM], const double v[DIM], double out[DIM])
{
	/* Delete these lines and write your code */
	(void)R; (void)v;
	for (int i = 0; i < DIM; i++) {
		out[i] = 0.0;
	}
}
