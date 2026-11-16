#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * A heater keeps an instrument near 20.0 C. The temperature sensor has
 * noise of up to +/- 0.3 C. We simulate 1000 time steps with each of two
 * controllers and count how many times the heater switches on or off.
 */
#define STEPS 1000
#define SETPOINT 20.0
#define BAND 0.5		/* hysteresis: half-width of the dead band */

static uint32_t rng_state = 2026U;

/* Repeatable noise between -0.3 and +0.3 */
double noise(void)
{
	rng_state = rng_state * 1664525U + 1013904223U;
	return ((double)(rng_state >> 8) / 16777216.0 - 0.5) * 0.6;
}

/* Run one controller. use_hysteresis selects the rule.
 * Returns the number of heater switches; stores the temperature range. */
int simulate(int use_hysteresis, double *min_temp, double *max_temp)
{
	double temp = 19.0;
	int heater_on = 0;
	int switches = 0;
	*min_temp = temp;
	*max_temp = temp;

	for (int step = 0; step < STEPS; step++) {
		double measured = temp + noise();
		int want_on;

		if (use_hysteresis) {
			if (measured < SETPOINT - BAND) {
				want_on = 1;
			}
			else if (measured > SETPOINT + BAND) {
				want_on = 0;
			}
			else {
				want_on = heater_on;	/* inside the band: change nothing */
			}
		}
		else {
			want_on = measured < SETPOINT;
		}

		if (want_on != heater_on) {
			switches++;
			heater_on = want_on;
		}

		temp += heater_on ? 0.05 : -0.04;	/* simple thermal model */
		if (temp < *min_temp) {
			*min_temp = temp;
		}
		if (temp > *max_temp) {
			*max_temp = temp;
		}
	}
	return switches;
}

int main(void)
{
	double lo = 0.0;
	double hi = 0.0;

	int naive = simulate(0, &lo, &hi);
	fprintf(stdout, "Without hysteresis: %4d heater switches, temperature %.2f to %.2f C\n", naive, lo, hi);

	rng_state = 2026U;	/* same noise for a fair comparison */
	int banded = simulate(1, &lo, &hi);
	fprintf(stdout, "With hysteresis:    %4d heater switches, temperature %.2f to %.2f C\n", banded, lo, hi);
	return EXIT_SUCCESS;
}
