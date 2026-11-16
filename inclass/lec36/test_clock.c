/*
 * In-Class Lecture 36 - Mission Clock test harness.
 * You do not need to change this file. Make every test pass.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "mission_clock.h"

/* ---- Simulated hardware ---- */

volatile uint32_t ticks_hi = 0;
volatile uint32_t ticks_lo = 0;

enum { INTERRUPT_NEVER, INTERRUPT_ONCE, INTERRUPT_ALWAYS };
static int interrupt_mode = INTERRUPT_NEVER;

/* The timer ISR. In ALWAYS mode, it simulates a broken timer whose high
 * half changes on every read. */
static void timer_isr(void)
{
	if (interrupt_mode == INTERRUPT_ALWAYS) {
		ticks_hi = ticks_hi + 1U;
		return;
	}
	ticks_lo = ticks_lo + 1U;
	if (ticks_lo == 0U) {
		ticks_hi = ticks_hi + 1U;
	}
}

void interrupt_point(void)
{
	if (interrupt_mode == INTERRUPT_ONCE) {
		interrupt_mode = INTERRUPT_NEVER;
		timer_isr();
	}
	else if (interrupt_mode == INTERRUPT_ALWAYS) {
		timer_isr();
	}
}

/* ---- Test helpers ---- */

static int passed = 0;
static int failed = 0;

static void check(int number, const char *name, int ok)
{
	fprintf(stdout, "Test %2d: %-52s %s\n", number, name, ok ? "PASS" : "FAIL");
	if (ok) {
		passed++;
	}
	else {
		failed++;
	}
}

static void set_clock(uint32_t hi, uint32_t lo, int mode)
{
	ticks_hi = hi;
	ticks_lo = lo;
	interrupt_mode = mode;
}

int main(void)
{
	/* Step 1 - elapsed_ms */
	check(1, "elapsed_ms: normal interval", elapsed_ms(1500U, 500U) == 1000U);
	check(2, "elapsed_ms: across the wraparound", elapsed_ms(200U, UINT32_MAX - 99U) == 300U);
	check(3, "elapsed_ms: zero", elapsed_ms(777U, 777U) == 0U);

	/* Step 2 - is_stale */
	check(4, "is_stale: fresh value", is_stale(1000U, 900U, 200U) == 0);
	check(5, "is_stale: stale value", is_stale(1000U, 700U, 200U) == 1);
	check(6, "is_stale: fresh across the wraparound", is_stale(50U, UINT32_MAX - 49U, 200U) == 0);
	check(7, "is_stale: stale across the wraparound", is_stale(500U, UINT32_MAX - 49U, 200U) == 1);
	check(8, "is_stale: time stamp from the future is rejected", is_stale(1000U, 1010U, 200U) == 1);

	/* Step 3 - clock_read */
	uint64_t now = 0;
	set_clock(7U, 12345U, INTERRUPT_NEVER);
	check(9, "clock_read: no interrupt",
	      clock_read(&now) == 0 && now == ((uint64_t)7U << 32 | 12345U));

	now = 0;
	set_clock(0U, UINT32_MAX, INTERRUPT_ONCE);
	check(10, "clock_read: interrupt at the worst moment",
	      clock_read(&now) == 0 && now == ((uint64_t)1U << 32));

	set_clock(0U, 0U, INTERRUPT_ALWAYS);
	check(11, "clock_read: broken timer is reported, not a hang", clock_read(&now) == -1);
	interrupt_mode = INTERRUPT_NEVER;

	/* Step 4 - to_flight_time */
	flight_time t = to_flight_time(1500U);
	check(12, "to_flight_time: 1.5 s", t.seconds == 1U && t.fraction == 32768U);

	t = to_flight_time(100U);
	check(13, "to_flight_time: 0.1 s (truncated)", t.seconds == 0U && t.fraction == 6553U);

	t = to_flight_time(86400000U);
	check(14, "to_flight_time: exactly one day", t.seconds == 86400U && t.fraction == 0U);

	t = to_flight_time((uint64_t)1U << 32);
	check(15, "to_flight_time: past the 32-bit limit (49.7 days)",
	      t.seconds == 4294967U && t.fraction == 19398U);

	fprintf(stdout, "\n%d passed, %d failed\n", passed, failed);
	return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
