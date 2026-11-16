/*
 * In-Class Lecture 38 - Sensor monitoring mission run.
 * You do not need to change this file. It calibrates R with your
 * compute_stats, filters the mission with your kf_step, writes estimate.csv
 * for plotting, and confirms sensor faults with a leaky bucket (Lecture 37).
 *
 * Usage: ./sensor_run calibration.csv mission.csv [Q] [bias]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kalman_filter.h"

enum { MAX_ROWS = 1000, BIAS_SAMPLE = 45, FILL = 2, LEAK = 1, TRIP = 4, BUCKET_MAX = 10 };

static double calib[MAX_ROWS];

int main(int argc, char *argv[])
{
	if (argc < 3 || argc > 5) {
		fprintf(stderr, "Usage: %s <calibration.csv> <mission.csv> [Q] [bias]\n", argv[0]);
		return EXIT_FAILURE;
	}
	double Q = (argc >= 4) ? strtod(argv[3], NULL) : 0.1;
	int add_bias = (argc == 5 && strcmp(argv[4], "bias") == 0);

	/* Calibrate R */
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}
	int n = 0;
	while (n < MAX_ROWS && fscanf(fp, "%lf", &calib[n]) == 1) {
		n++;
	}
	fclose(fp);

	double mean = 0.0;
	double R = 0.0;
	if (compute_stats(calib, n, &mean, &R) != 0) {
		fprintf(stderr, "Calibration failed\n");
		return EXIT_FAILURE;
	}
	fprintf(stdout, "Calibration: %d samples, mean %.3f C, R = %.3f\n", n, mean, R);
	fprintf(stdout, "Filter: Q = %.4f, gate = 3.0 std devs%s\n\n", Q, add_bias ? ", +3.0 C bias at sample 45" : "");

	/* Fly the mission */
	FILE *in = fopen(argv[2], "r");
	FILE *out = fopen("estimate.csv", "w");
	if (in == NULL || out == NULL) {
		fprintf(stderr, "Could not open %s or estimate.csv\n", argv[2]);
		if (in != NULL) {
			fclose(in);
		}
		if (out != NULL) {
			fclose(out);
		}
		return EXIT_FAILURE;
	}
	fprintf(out, "sample,true,measured,estimate\n");

	kalman1d kf = { 0.0, R, Q, R, 3.0 };
	kf_result res;
	int bucket = 0;
	int status = EXIT_SUCCESS;

	for (int row = 0; row < MAX_ROWS; row++) {
		int k = 0;
		double truth = 0.0;
		double z = 0.0;
		if (fscanf(in, "%d,%lf,%lf", &k, &truth, &z) != 3) {
			break;
		}
		if (add_bias && k >= BIAS_SAMPLE) {
			z += 3.0;
		}
		if (row == 0) {
			kf.x = z;
		}
		else if (kf_step(&kf, z, &res) == 0 && res.rejected) {
			bucket = (bucket + FILL > BUCKET_MAX) ? BUCKET_MAX : bucket + FILL;
			fprintf(stdout, "sample %2d: %5.1f std devs, REJECTED (bucket %d)\n", k, res.surprise, bucket);
			if (bucket >= TRIP) {
				fprintf(stdout, "          SENSOR FAULT confirmed at sample %d\n", k);
				status = EXIT_FAILURE;
			}
		}
		else if (bucket >= LEAK) {
			bucket -= LEAK;
		}
		fprintf(out, "%d,%.2f,%.2f,%.3f\n", k, truth, z, kf.x);
		if (status == EXIT_FAILURE) {
			break;
		}
	}
	fclose(in);
	fclose(out);
	fprintf(stdout, "\nWrote estimate.csv\n");
	return status;
}
