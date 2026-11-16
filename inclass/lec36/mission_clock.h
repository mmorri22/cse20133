#ifndef MISSION_CLOCK_H
#define MISSION_CLOCK_H

#include <stdint.h>

/* CCSDS-style time: whole seconds plus a binary fraction (1/65536 s) */
typedef struct {
	uint32_t seconds;
	uint32_t fraction;	/* 0 to 65535 */
} flight_time;

enum {
	FRACTION_PER_SECOND = 65536,
	MS_PER_SECOND = 1000,
	MAX_READ_TRIES = 3
};

/* ---- The simulated hardware, provided in test_clock.c ---- */

/* The two halves of the 64-bit millisecond counter, updated by the timer ISR */
extern volatile uint32_t ticks_hi;
extern volatile uint32_t ticks_lo;

/* Call this between your two loads. When a test enables it, the timer
 * interrupt runs here, at the worst possible moment. */
void interrupt_point(void);

/* ---- You will write these in mission_clock.c ---- */

/* Milliseconds from start to now, correct across a wraparound */
uint32_t elapsed_ms(uint32_t now, uint32_t start);

/* 1 if a value time-stamped at stamp is older than max_age_ms, else 0 */
int is_stale(uint32_t now, uint32_t stamp, uint32_t max_age_ms);

/* Read the 64-bit counter safely into *now. Returns 0 on success, or -1 if
 * the counter did not settle within MAX_READ_TRIES attempts. */
int clock_read(uint64_t *now);

/* Convert a millisecond count to seconds plus a binary fraction.
 * The fraction is truncated, not rounded. */
flight_time to_flight_time(uint64_t ms);

#endif
