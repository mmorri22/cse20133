/*
 * In-Class Lecture 38 - Kalman Filter
 *
 * INSTRUCTOR SOLUTION
 */
#include <stddef.h>
#include <math.h>

#include "kalman_filter.h"

/* Step 1: two passes, mean first, then the sample variance */
int compute_stats(const double data[], int n, double *mean, double *variance)
{
	if (data == NULL || mean == NULL || variance == NULL || n < 2) {
		return -1;
	}
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += data[i];
	}
	double m = sum / n;

	double sum_sq = 0.0;
	for (int i = 0; i < n; i++) {
		sum_sq += (data[i] - m) * (data[i] - m);
	}
	*mean = m;
	*variance = sum_sq / (n - 1);
	return 0;
}

/* Steps 2 and 3: predict, test the innovation against the gate, then update */
int kf_step(kalman1d *kf, double z, kf_result *out)
{
	if (kf == NULL || out == NULL) {
		return -1;
	}

	/* Predict */
	double x_pred = kf->x;
	double P_pred = kf->P + kf->Q;

	/* Innovation and its expected variance */
	double S = P_pred + kf->R;
	out->innovation = z - x_pred;
	out->surprise = out->innovation / sqrt(S);

	/* Gate: reject, but still grow the uncertainty */
	if (fabs(out->surprise) > kf->gate) {
		out->rejected = 1;
		out->K = 0.0;
		kf->x = x_pred;
		kf->P = P_pred;
		return 0;
	}

	/* Gain and update */
	out->rejected = 0;
	out->K = P_pred / S;
	kf->x = x_pred + out->K * out->innovation;
	kf->P = (1.0 - out->K) * P_pred;
	return 0;
}
