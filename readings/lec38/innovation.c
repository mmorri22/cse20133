#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * The same Kalman filter as a fault detector. The innovation is the
 * difference between what the sensor says and what the filter predicted.
 * Divided by its expected size, it says how surprising each measurement is.
 *
 * Usage: ./innovation mission.csv           (the data as recorded)
 *        ./innovation mission.csv bias      (sensor develops a +3.0 C bias at sample 45)
 */
#define MAX_ROWS 1000
#define R_MEASURED 0.528
#define Q_TUNED 0.1
#define GATE 3.0		/* more than 3 standard deviations is suspicious */
#define BIAS_SAMPLE 45
#define BIAS_C 3.0

/* Leaky bucket from Lecture 37 */
#define FILL 2
#define LEAK 1
#define TRIP 4
#define BUCKET_MAX 10

int main(int argc, char *argv[])
{
	if (argc != 2 && argc != 3) {
		fprintf(stderr, "Usage: %s <mission_file> [bias]\n", argv[0]);
		return EXIT_FAILURE;
	}
	int add_bias = (argc == 3 && strcmp(argv[2], "bias") == 0);

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}

	double x = 0.0;
	double P = R_MEASURED;
	int bucket = 0;
	int first = 1;
	double last_truth = 0.0;

	for (int row = 0; row < MAX_ROWS; row++) {
		int k = 0;
		double truth = 0.0;
		double z = 0.0;
		if (fscanf(fp, "%d,%lf,%lf", &k, &truth, &z) != 3) {
			break;
		}
		last_truth = truth;
		if (add_bias && k >= BIAS_SAMPLE) {
			z += BIAS_C;
		}
		if (first) {
			x = z;
			first = 0;
			continue;
		}

		/* Predict */
		double P_pred = P + Q_TUNED;

		/* Innovation, and its expected variance S */
		double innovation = z - x;
		double S = P_pred + R_MEASURED;
		double surprise = innovation / sqrt(S);

		if (fabs(surprise) > GATE) {
			/* Gate: do NOT let a suspicious measurement move the estimate */
			bucket += FILL;
			if (bucket > BUCKET_MAX) {
				bucket = BUCKET_MAX;
			}
			P = P_pred;
			fprintf(stdout, "sample %2d: measured %6.2f, predicted %6.2f, %4.1f std devs: REJECTED (bucket %d)\n",
				k, z, x, surprise, bucket);
			if (bucket >= TRIP) {
				fprintf(stdout, "          SENSOR FAULT confirmed: switch to backup sensor\n");
				fclose(fp);
				return EXIT_FAILURE;
			}
		}
		else {
			double K = P_pred / S;
			x = x + K * innovation;
			P = (1.0 - K) * P_pred;
			if (bucket >= LEAK) {
				bucket -= LEAK;
			}
		}
	}
	fclose(fp);
	fprintf(stdout, "Mission complete: no sensor fault confirmed. Final estimate %.2f C (true %.2f C)\n",
		x, last_truth);
	return EXIT_SUCCESS;
}
