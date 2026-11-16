#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Two simple ways to reduce noise, and what they cost.
 * mission.csv: sample, true temperature, measured temperature.
 * At sample 36, the true temperature jumps by about 1.6 C.
 */
#define MAX_SAMPLES 1000
#define WINDOW 8		/* moving average length */
#define ALPHA 0.2		/* exponential smoothing weight */
#define STEP_SAMPLE 36

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <mission_file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}

	double window[WINDOW] = { 0.0 };
	double window_sum = 0.0;
	double ema = 0.0;

	double sq_raw = 0.0;
	double sq_ma = 0.0;
	double sq_ema = 0.0;
	int n = 0;

	fprintf(stdout, "%6s %8s %8s %10s %10s\n", "sample", "true", "measured", "moving avg", "exponential");
	for (int row = 0; row < MAX_SAMPLES; row++) {
		int k = 0;
		double truth = 0.0;
		double meas = 0.0;
		if (fscanf(fp, "%d,%lf,%lf", &k, &truth, &meas) != 3) {
			break;
		}

		/* Moving average: replace the oldest value in a ring buffer */
		window_sum += meas - window[row % WINDOW];
		window[row % WINDOW] = meas;
		int count = (row + 1 < WINDOW) ? row + 1 : WINDOW;
		double ma = window_sum / count;

		/* Exponential smoothing: move a fraction ALPHA toward each new sample */
		ema = (row == 0) ? meas : ema + ALPHA * (meas - ema);

		sq_raw += (meas - truth) * (meas - truth);
		sq_ma += (ma - truth) * (ma - truth);
		sq_ema += (ema - truth) * (ema - truth);
		n++;

		if (k >= STEP_SAMPLE - 2 && k <= STEP_SAMPLE + 8) {
			fprintf(stdout, "%6d %8.2f %8.2f %10.2f %10.2f\n", k, truth, meas, ma, ema);
		}
	}
	fclose(fp);

	if (n > 0) {
		fprintf(stdout, "\nRMS error over %d samples:\n", n);
		fprintf(stdout, "  measured:     %.3f C\n", sqrt(sq_raw / n));
		fprintf(stdout, "  moving avg:   %.3f C\n", sqrt(sq_ma / n));
		fprintf(stdout, "  exponential:  %.3f C\n", sqrt(sq_ema / n));
	}
	return EXIT_SUCCESS;
}
