#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * A 64-bit millisecond counter kept as two 32-bit halves, as on a 32-bit
 * processor. A timer interrupt updates both halves. Here, the interrupt is
 * SIMULATED so we can make it happen at exactly the worst moment.
 */
static volatile uint32_t ticks_hi = 0;
static volatile uint32_t ticks_lo = 0;

/* When nonzero, the next call to interrupt_point() runs the timer interrupt */
static int interrupt_pending = 0;

/* The timer interrupt: add one millisecond, carrying into the high half */
void timer_isr(void)
{
	ticks_lo = ticks_lo + 1U;
	if (ticks_lo == 0U) {
		ticks_hi = ticks_hi + 1U;
	}
}

/* On real hardware an interrupt can arrive between ANY two instructions.
 * We place this call between the two loads to force the worst case. */
void interrupt_point(void)
{
	if (interrupt_pending) {
		interrupt_pending = 0;
		timer_isr();
	}
}

/* Read the high half, then the low half (Ama's now() on slide 47) */
uint64_t now_unsafe(void)
{
	uint32_t hi = ticks_hi;
	interrupt_point();
	uint32_t lo = ticks_lo;
	return ((uint64_t)hi << 32) | lo;
}

#define MAX_TRIES 3

/* Re-read until the high half did not change, with a Rule 2 bound.
 * Returns 0 on success, -1 if the counter never settled. */
int now_safe(uint64_t *now)
{
	for (int attempt = 0; attempt < MAX_TRIES; attempt++) {
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

int main(void)
{
	/* One millisecond before the low half wraps to zero */
	ticks_hi = 0U;
	ticks_lo = UINT32_MAX;
	uint64_t before = ((uint64_t)ticks_hi << 32) | ticks_lo;
	fprintf(stdout, "Time before the read:   %llu ms\n", (unsigned long long)before);

	interrupt_pending = 1;
	uint64_t unsafe = now_unsafe();
	fprintf(stdout, "now_unsafe() returned:  %llu ms\n", (unsigned long long)unsafe);
	if (unsafe < before) {
		fprintf(stdout, "  TIME WENT BACKWARDS by %.1f days\n",
			(double)(before - unsafe) / 86400000.0);
	}

	/* Reset to the same moment and try the safe version */
	ticks_hi = 0U;
	ticks_lo = UINT32_MAX;
	interrupt_pending = 1;
	uint64_t safe = 0;
	if (now_safe(&safe) == 0) {
		fprintf(stdout, "now_safe() returned:    %llu ms\n", (unsigned long long)safe);
	}
	else {
		fprintf(stdout, "ANOMALY: clock did not settle after %d tries\n", MAX_TRIES);
	}
	return EXIT_SUCCESS;
}
