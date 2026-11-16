#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

/* A one-dimensional Kalman filter with a measurement gate */
typedef struct {
	double x;	/* estimate */
	double P;	/* variance of the estimate */
	double Q;	/* process noise */
	double R;	/* measurement noise */
	double gate;	/* reject measurements more than this many standard deviations away */
} kalman1d;

/* What happened during one step, for logging and fault detection */
typedef struct {
	double K;		/* gain used (0.0 if the measurement was rejected) */
	double innovation;	/* measurement minus prediction */
	double surprise;	/* innovation divided by sqrt(S): in standard deviations */
	int rejected;		/* 1 if the gate rejected the measurement */
} kf_result;

/* Step 1: the mean and the sample variance (divide by n - 1) of n values.
 * Returns 0 on success, or -1 if n < 2 or any pointer is NULL. */
int compute_stats(const double data[], int n, double *mean, double *variance);

/* Steps 2 and 3: one predict / gate / update cycle with measurement z.
 * Returns 0 on success, or -1 if kf or out is NULL. */
int kf_step(kalman1d *kf, double z, kf_result *out);

#endif
