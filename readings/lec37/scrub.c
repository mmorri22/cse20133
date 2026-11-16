#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * How long does a TMR value survive in a radiation environment?
 * Each hour, there is a small chance that a bit flips in one random copy.
 * The voter fails when it returns a wrong value or finds no quorum.
 *
 * "Scrubbing" means writing the voted value back into all three copies,
 * erasing any single flip before a second one can join it.
 */
#define FLIP_CHANCE_PER_HOUR 0.01
#define TRIALS 1000
#define MAX_HOURS 1000000U	/* about 114 years. Rule 2: every loop has a fixed bound */

typedef struct {
	int16_t copy[3];
} tmr_reading;

/* A small repeatable pseudo-random generator, so results match every run */
static uint32_t rng_state = 12345U;

double rand_unit(void)
{
	rng_state = rng_state * 1664525U + 1013904223U;
	return (double)(rng_state >> 8) / 16777216.0;
}

int rand_below(int n)
{
	return (int)(rand_unit() * n);
}

/* Returns 1 if the vote is wrong or has no quorum */
int vote_fails(tmr_reading *r, int16_t true_value, int scrub)
{
	int16_t result;
	if (r->copy[0] == r->copy[1] || r->copy[0] == r->copy[2]) {
		result = r->copy[0];
	}
	else if (r->copy[1] == r->copy[2]) {
		result = r->copy[1];
	}
	else {
		return 1;
	}
	if (result != true_value) {
		return 1;
	}
	if (scrub) {
		r->copy[0] = result;
		r->copy[1] = result;
		r->copy[2] = result;
	}
	return 0;
}

/* Average hours until the first voting failure, over the trials that failed.
 * Stores the number of trials that failed in *failures. */
double mean_hours_to_failure(unsigned scrub_interval_hours, int *failures)
{
	const int16_t true_value = 2150;
	double total = 0.0;
	*failures = 0;

	for (int trial = 0; trial < TRIALS; trial++) {
		tmr_reading r = { { true_value, true_value, true_value } };
		unsigned hour = 1;
		for (; hour < MAX_HOURS; hour++) {
			if (rand_unit() < FLIP_CHANCE_PER_HOUR) {
				int which = rand_below(3);
				int bit = rand_below(16);
				r.copy[which] = (int16_t)((uint16_t)r.copy[which] ^ (uint16_t)(1U << bit));
			}
			int scrub = (scrub_interval_hours > 0U) && (hour % scrub_interval_hours == 0U);
			if (vote_fails(&r, true_value, scrub)) {
				total += hour;
				(*failures)++;
				break;
			}
		}
	}
	return (*failures > 0) ? total / *failures : 0.0;
}

void report(const char *label, unsigned scrub_interval_hours)
{
	int failures = 0;
	double mean = mean_hours_to_failure(scrub_interval_hours, &failures);
	if (failures > 0) {
		fprintf(stdout, "%-14s %22.0f hours\n", label, mean);
	}
	else {
		fprintf(stdout, "%-14s   no failure in %d trials of %u hours\n", label, TRIALS, MAX_HOURS);
	}
}

int main(void)
{
	fprintf(stdout, "Chance of a bit flip each hour: %.2f\n\n", FLIP_CHANCE_PER_HOUR);
	fprintf(stdout, "%-14s %28s\n", "Scrubbing", "Mean time to voting failure");
	report("Never", 0U);
	report("Once a week", 168U);
	report("Once a day", 24U);
	report("Every hour", 1U);
	return EXIT_SUCCESS;
}
