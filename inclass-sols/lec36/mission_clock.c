/*
 * In-Class Lecture 36 - Mission Clock
 *
 * INSTRUCTOR SOLUTION
 */
#include <stddef.h>

#include "mission_clock.h"

/* Step 1: unsigned subtraction is defined to wrap, so it always gives the
 * elapsed time, as long as the interval is under 49.7 days */
uint32_t elapsed_ms(uint32_t now, uint32_t start)
{
	return now - start;
}

/* Step 2: a time stamp from the future gives a huge "age" and is rejected */
int is_stale(uint32_t now, uint32_t stamp, uint32_t max_age_ms)
{
	return elapsed_ms(now, stamp) > max_age_ms;
}

/* Step 3: re-read until the high half is unchanged, within a fixed bound */
int clock_read(uint64_t *now)
{
	if (now == NULL) {
		return -1;
	}
	for (int attempt = 0; attempt < MAX_READ_TRIES; attempt++) {
		uint32_t hi = ticks_hi;
		interrupt_point();
		uint32_t lo = ticks_lo;
		if (hi == ticks_hi) {
			*now = ((uint64_t)hi << 32) | lo;
			return 0;
		}
	}
	return -1;
}

/* Step 4: whole seconds by division; the remainder becomes the fraction.
 * Every step is integer arithmetic on the total, so nothing accumulates. */
flight_time to_flight_time(uint64_t ms)
{
	flight_time result;
	result.seconds = (uint32_t)(ms / MS_PER_SECOND);
	result.fraction = (uint32_t)((ms % MS_PER_SECOND) * FRACTION_PER_SECOND / MS_PER_SECOND);
	return result;
}
