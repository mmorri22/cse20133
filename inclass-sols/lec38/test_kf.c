/*
 * In-Class Lecture 38 - Kalman filter test harness.
 * You do not need to change this file. Make every test pass.
 *
 * Floating-point results are never compared with ==. Each test checks
 * that the answer is within a tolerance of the expected value.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "kalman_filter.h"

#define TOL 1.0e-9

static int passed = 0;
static int failed = 0;

static void check(int number, const char *name, int ok)
{
	fprintf(stdout, "Test %2d: %-52s %s\n", number, name, ok ? "PASS" : "FAIL");
	if (ok) {
		passed++;
	}
	else {
		failed++;
	}
}

static int near(double a, double b, double tol)
{
	return fabs(a - b) <= tol;
}

int main(void)
{
	double mean = 0.0;
	double var = 0.0;

	/* Step 1 - compute_stats */
	const double d4[] = { 19.0, 20.0, 21.0, 22.0 };
	check(1, "stats: returns 0 for valid input", compute_stats(d4, 4, &mean, &var) == 0);
	check(2, "stats: mean", near(mean, 20.5, TOL));
	check(3, "stats: sample variance (n - 1)", near(var, 1.6666666666666667, TOL));

	const double d1[] = { 20.0 };
	check(4, "stats: fewer than 2 values is rejected", compute_stats(d1, 1, &mean, &var) == -1);
	check(5, "stats: NULL is rejected", compute_stats(NULL, 4, &mean, &var) == -1);

	/* Step 2 - kf_step, a normal update */
	kalman1d kf = { 20.0, 0.5, 0.1, 0.5, 3.0 };
	kf_result res = { 0.0, 0.0, 0.0, -1 };
	check(6, "kf_step: returns 0 for valid input", kf_step(&kf, 21.0, &res) == 0);
	check(7, "kf_step: gain K", near(res.K, 0.5454545454545454, TOL));
	check(8, "kf_step: updated estimate x", near(kf.x, 20.545454545454547, TOL));
	check(9, "kf_step: updated variance P", near(kf.P, 0.27272727272727276, TOL));
	check(10, "kf_step: innovation and surprise",
	      near(res.innovation, 1.0, TOL) && near(res.surprise, 0.9534625892455922, TOL) && res.rejected == 0);

	/* Step 3 - kf_step, the gate */
	kf = (kalman1d){ 20.0, 0.5, 0.1, 0.5, 3.0 };
	(void)kf_step(&kf, 25.0, &res);
	check(11, "gate: 4.77 std devs high is rejected", res.rejected == 1 && near(res.surprise, 4.767312946227961, TOL));
	check(12, "gate: rejected reading does not move x", near(kf.x, 20.0, TOL));
	check(13, "gate: rejected reading still grows P", near(kf.P, 0.6, TOL));

	kf = (kalman1d){ 20.0, 0.5, 0.1, 0.5, 3.0 };
	(void)kf_step(&kf, 15.0, &res);
	check(14, "gate: 4.77 std devs LOW is also rejected", res.rejected == 1 && near(kf.x, 20.0, TOL));

	/* Step 4 - convergence to the theoretical steady-state gain */
	kf = (kalman1d){ 20.0, 0.528, 0.1, 0.528, 3.0 };
	for (int i = 0; i < 100; i++) {
		(void)kf_step(&kf, 20.0, &res);
	}
	double p_ss = (kf.Q + sqrt(kf.Q * kf.Q + 4.0 * kf.Q * kf.R)) / 2.0;
	check(15, "kf_step: K converges to the steady-state gain", near(res.K, p_ss / (p_ss + kf.R), 1.0e-9));

	check(16, "kf_step: NULL is rejected", kf_step(NULL, 20.0, &res) == -1 && kf_step(&kf, 20.0, NULL) == -1);

	fprintf(stdout, "\n%d passed, %d failed\n", passed, failed);
	return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
