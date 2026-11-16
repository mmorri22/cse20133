#include <stdio.h>
#include <stdlib.h>

/*
 * A battery voltage sensor, sampled once per second. Below 26.0 V is
 * "under-voltage". The noisy samples include three isolated spikes, then
 * the battery really does start to fail at sample 20.
 */
#define NUM_SAMPLES 30
#define UNDER_VOLTAGE 26.0

/* Leaky bucket settings */
#define FILL_PER_BAD 2		/* each bad sample adds 2 */
#define LEAK_PER_GOOD 1		/* each good sample drains 1 */
#define TRIP_LEVEL 6		/* the fault is declared at 6 */
#define BUCKET_MAX 20		/* the bucket itself has a bound */

int main(void)
{
	const double volts[NUM_SAMPLES] = {
		28.1, 28.0, 25.2, 28.2, 28.1, 27.9, 28.0, 28.1, 25.4, 28.0,
		28.1, 28.2, 25.1, 25.3, 28.0, 27.9, 28.1, 28.0, 28.1, 27.9,
		25.6, 25.4, 25.2, 25.1, 24.9, 24.8, 24.6, 24.5, 24.3, 24.1
	};

	int naive_tripped_at = -1;
	int bucket = 0;
	int bucket_tripped_at = -1;

	fprintf(stdout, "%6s %8s %8s %8s\n", "sample", "volts", "bad?", "bucket");
	for (int i = 0; i < NUM_SAMPLES; i++) {
		int bad = volts[i] < UNDER_VOLTAGE;

		/* Naive: one bad sample declares the fault */
		if (bad && naive_tripped_at < 0) {
			naive_tripped_at = i;
		}

		/* Leaky bucket: bad samples fill it, good samples drain it */
		if (bad) {
			bucket += FILL_PER_BAD;
			if (bucket > BUCKET_MAX) {
				bucket = BUCKET_MAX;
			}
		}
		else if (bucket >= LEAK_PER_GOOD) {
			bucket -= LEAK_PER_GOOD;
		}
		if (bucket >= TRIP_LEVEL && bucket_tripped_at < 0) {
			bucket_tripped_at = i;
		}

		fprintf(stdout, "%6d %8.1f %8s %8d\n", i, volts[i], bad ? "BAD" : "", bucket);
	}

	fprintf(stdout, "\nNaive check declared under-voltage at sample %d\n", naive_tripped_at);
	fprintf(stdout, "Leaky bucket declared under-voltage at sample %d\n", bucket_tripped_at);
	return EXIT_SUCCESS;
}
