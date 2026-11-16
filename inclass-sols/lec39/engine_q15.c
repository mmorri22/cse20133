/* Q15 engine: 16-bit fixed point, as on a DSP.
 * A value v between -1 and 1 is stored as the int16_t closest to v * 32768.
 *
 * INSTRUCTOR SOLUTION
 */
#include <stdint.h>
#include <math.h>

#include "engine.h"

const char ENGINE_NAME[] = "Q15";
const double ENGINE_TOLERANCE = 1.0e-3;

/* Step 1: round to the nearest Q15 value, saturating at the ends of the range.
 * 1.0 itself cannot be represented: it saturates to 32767 / 32768. */
int16_t to_q15(double v)
{
	double scaled = round(v * 32768.0);
	if (scaled > 32767.0) {
		return INT16_MAX;
	}
	if (scaled < -32768.0) {
		return INT16_MIN;
	}
	return (int16_t)scaled;
}

/* Step 2: products of two Q15 values have 30 fraction bits. Accumulate in a
 * wide integer, shift back by 15, and saturate before narrowing to Q15. */
void rotate(const double R[DIM][DIM], const double v[DIM], double out[DIM])
{
	for (int i = 0; i < DIM; i++) {
		int64_t acc = 0;
		for (int j = 0; j < DIM; j++) {
			acc += (int32_t)to_q15(R[i][j]) * (int32_t)to_q15(v[j]);
		}
		int64_t q = acc >> 15;
		if (q > INT16_MAX) {
			q = INT16_MAX;
		}
		if (q < INT16_MIN) {
			q = INT16_MIN;
		}
		out[i] = (double)q / 32768.0;
	}
}
