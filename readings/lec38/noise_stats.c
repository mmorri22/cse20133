#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Characterize a sensor before filtering it. The sensor was held at a known
 * 20.00 C, so every difference from 20.00 is noise.
 */
#define MAX_SAMPLES 1000	/* Rule 2 and Rule 3: a fixed bound, a fixed array */
#define KNOWN_TEMP 20.0

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <calibration_file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}

	static double samples[MAX_SAMPLES];
	int n = 0;
	while (n < MAX_SAMPLES && fscanf(fp, "%lf", &samples[n]) == 1) {
		n++;
	}
	fclose(fp);
	if (n < 2) {
		fprintf(stderr, "Need at least two samples\n");
		return EXIT_FAILURE;
	}

	/* Pass 1: the mean */
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += samples[i];
	}
	double mean = sum / n;

	/* Pass 2: the variance, the average squared distance from the mean */
	double sum_sq = 0.0;
	for (int i = 0; i < n; i++) {
		sum_sq += (samples[i] - mean) * (samples[i] - mean);
	}
	double variance = sum_sq / (n - 1);
	double std_dev = sqrt(variance);

	/* How many samples fall within 1, 2, and 3 standard deviations? */
	int within[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < n; i++) {
		double dist = fabs(samples[i] - mean);
		for (int s = 1; s <= 3; s++) {
			if (dist <= s * std_dev) {
				within[s]++;
			}
		}
	}

	fprintf(stdout, "Samples:             %d\n", n);
	fprintf(stdout, "Mean:                %.3f C  (bias %.3f C)\n", mean, mean - KNOWN_TEMP);
	fprintf(stdout, "Standard deviation:  %.3f C\n", std_dev);
	fprintf(stdout, "Variance (R):        %.3f C^2\n\n", variance);
	for (int s = 1; s <= 3; s++) {
		fprintf(stdout, "Within %d std dev:    %5.1f%%\n", s, 100.0 * within[s] / n);
	}
	return EXIT_SUCCESS;
}
