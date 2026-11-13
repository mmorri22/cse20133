#include <stdio.h>
#include <stdint.h>

/*
 * A spacecraft clock ticks every 0.1 seconds for one day.
 * Three ways to keep track of elapsed time.
 */
#define TICKS_PER_DAY 864000

int main(void)
{
	float time_float = 0.0f;
	double time_double = 0.0;
	uint32_t ticks = 0;

	for (uint32_t i = 0; i < TICKS_PER_DAY; i++) {
		time_float += 0.1f;
		time_double += 0.1;
		ticks++;
	}

	fprintf(stdout, "Expected:            86400.000000 s\n");
	fprintf(stdout, "float accumulator:   %.6f s\n", (double)time_float);
	fprintf(stdout, "double accumulator:  %.6f s\n", time_double);
	fprintf(stdout, "integer tick count:  %u ticks = %u.%u s\n", ticks, ticks / 10, ticks % 10);
	return 0;
}
