#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TIMEOUT_MS 1000U

/* WRONG: the sum start + TIMEOUT_MS can wrap around to a small number */
int timed_out_naive(uint32_t now, uint32_t start)
{
	return now >= start + TIMEOUT_MS;
}

/* RIGHT: unsigned subtraction wraps too, so it always gives elapsed time */
int timed_out_safe(uint32_t now, uint32_t start)
{
	return now - start >= TIMEOUT_MS;
}

int main(void)
{
	/* The command was sent 300 ms before the counter wraps to zero */
	const uint32_t start = UINT32_MAX - 299U;

	fprintf(stdout, "start = %u   start + TIMEOUT_MS = %u\n\n", start, start + TIMEOUT_MS);
	fprintf(stdout, "%12s %12s %10s %10s\n", "now", "elapsed ms", "naive", "safe");

	for (uint32_t step = 0; step <= 12; step++) {
		uint32_t now = start + step * 100U;	/* wraps past zero at step 3 */
		fprintf(stdout, "%12u %12u %10s %10s\n", now, now - start,
			timed_out_naive(now, start) ? "TIMEOUT" : "waiting",
			timed_out_safe(now, start) ? "TIMEOUT" : "waiting");
	}
	return EXIT_SUCCESS;
}
