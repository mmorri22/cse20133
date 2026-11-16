#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * A spacecraft clock stores time the CCSDS way: whole seconds, plus a binary
 * fraction in units of 1/65536 of a second. Its timer ticks every 0.1 s.
 * Three ways to keep that clock for one day.
 */
#define TICKS_PER_DAY 864000U
#define FRACTION_PER_SECOND 65536U

typedef struct {
	uint32_t seconds;
	uint32_t fraction;	/* 0 to 65535, in units of 1/65536 s */
} flight_time;

/* Convert a flight_time to seconds as a double, for display ONLY */
double to_display(flight_time t)
{
	return (double)t.seconds + (double)t.fraction / FRACTION_PER_SECOND;
}

int main(void)
{
	/* Method 1: float accumulation (Reading 33-1) */
	float time_float = 0.0f;

	/* Method 2: integers, but add a ROUNDED 0.1 s each tick.
	 * 0.1 s = 6553.6 fraction units, which must be rounded to 6554. */
	flight_time accumulated = { 0, 0 };
	const uint32_t tick_fraction = 6554U;

	/* Method 3: count ticks exactly; convert the total only when needed */
	uint32_t ticks = 0;

	for (uint32_t i = 0; i < TICKS_PER_DAY; i++) {
		time_float += 0.1f;

		accumulated.fraction += tick_fraction;
		if (accumulated.fraction >= FRACTION_PER_SECOND) {
			accumulated.seconds++;
			accumulated.fraction -= FRACTION_PER_SECOND;
		}

		ticks++;
	}

	/* Convert the exact tick count: 10 ticks per second, remainder to fraction */
	flight_time exact;
	exact.seconds = ticks / 10U;
	exact.fraction = (ticks % 10U) * FRACTION_PER_SECOND / 10U;

	fprintf(stdout, "Expected after one day:        86400.000000 s\n");
	fprintf(stdout, "1. float accumulation:         %.6f s\n", (double)time_float);
	fprintf(stdout, "2. integer, rounded increment: %.6f s\n", to_display(accumulated));
	fprintf(stdout, "3. integer tick count:         %.6f s\n", to_display(exact));
	return EXIT_SUCCESS;
}
