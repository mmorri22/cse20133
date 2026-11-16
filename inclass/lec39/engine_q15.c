/* Q15 engine: 16-bit fixed point, as on a DSP.
 * A value v between -1 and 1 is stored as the int16_t closest to v * 32768. */
#include <stdint.h>
#include <math.h>

#include "engine.h"

const char ENGINE_NAME[] = "Q15";
const double ENGINE_TOLERANCE = 1.0e-3;

/* Step 1 */
int16_t to_q15(double v)
{
	/* Delete these lines and write your code */
	(void)v;
	return 0;
}

/* Step 2 */
void rotate(const double R[DIM][DIM], const double v[DIM], double out[DIM])
{
	/* Delete these lines and write your code */
	(void)R; (void)v;
	for (int i = 0; i < DIM; i++) {
		out[i] = 0.0;
	}
}
