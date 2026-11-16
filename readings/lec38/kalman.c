#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * A one-dimensional Kalman filter estimating a temperature from noisy
 * measurements. mission.csv: sample, true temperature, measured temperature.
 */
#define MAX_SAMPLES 1000
#define R_MEASURED 0.528	/* sensor variance, from noise_stats */
#define STEP_SAMPLE 36

typedef struct {
	double x;	/* estimate */
	double P;	/* variance of the estimate: how unsure we are */
	double Q;	/* process noise: how much the true value can change per step */
	double R;	/* measurement noise: how noisy the sensor is */
} kalman1d;

/* One predict / gain / update cycle. Returns the gain K. */
double kalman_step(kalman1d *kf, double z)
{
	/* Predict: the temperature stays the same, but we grow less sure */
	double x_pred = kf->x;
	double P_pred = kf->P + kf->Q;

	/* Gain: how much to trust the measurement over the prediction */
	double K = P_pred / (P_pred + kf->R);

	/* Update: move toward the measurement by K, and become more sure */
	kf->x = x_pred + K * (z - x_pred);
	kf->P = (1.0 - K) * P_pred;
	return K;
}

static int k_col[MAX_SAMPLES];
static double truth[MAX_SAMPLES];
static double meas[MAX_SAMPLES];

int load(const char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1;
	}
	int n = 0;
	while (n < MAX_SAMPLES && fscanf(fp, "%d,%lf,%lf", &k_col[n], &truth[n], &meas[n]) == 3) {
		n++;
	}
	fclose(fp);
	return n;
}

/* Run the whole mission with one value of Q. Reports RMS error and how many
 * samples after the step the estimate takes to come within 0.5 C. */
void run(int n, double Q, int show_steps)
{
	kalman1d kf = { meas[0], R_MEASURED, Q, R_MEASURED };
	double sq = 0.0;
	int lag = -1;
	double K = 0.0;

	for (int i = 1; i < n; i++) {
		K = kalman_step(&kf, meas[i]);
		sq += (kf.x - truth[i]) * (kf.x - truth[i]);
		if (lag < 0 && k_col[i] >= STEP_SAMPLE && fabs(kf.x - truth[i]) < 0.5) {
			lag = k_col[i] - STEP_SAMPLE;
		}
		if (show_steps && i <= 6) {
			fprintf(stdout, "%6d %9.2f %9.2f %7.3f %9.3f\n", k_col[i], meas[i], kf.x, K, kf.P);
		}
	}

	if (!show_steps) {
		fprintf(stdout, "%8.3f %8.3f %10.3f ", Q, K, sqrt(sq / (n - 1)));
		if (lag >= 0) {
			fprintf(stdout, "%14d\n", lag);
		}
		else {
			fprintf(stdout, "%14s\n", "never");
		}
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <mission_file>\n", argv[0]);
		return EXIT_FAILURE;
	}
	int n = load(argv[1]);
	if (n < 2) {
		fprintf(stderr, "Could not read %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	fprintf(stdout, "The first steps, with Q = 0.1:\n");
	fprintf(stdout, "%6s %9s %9s %7s %9s\n", "sample", "measured", "estimate", "gain K", "variance P");
	run(n, 0.1, 1);

	fprintf(stdout, "\nTuning Q (R = %.3f from calibration):\n", R_MEASURED);
	fprintf(stdout, "%8s %8s %10s %14s\n", "Q", "final K", "RMS error", "lag after step");
	const double q_values[] = { 0.001, 0.01, 0.1, 1.0 };
	for (int i = 0; i < 4; i++) {
		run(n, q_values[i], 0);
	}
	return EXIT_SUCCESS;
}
