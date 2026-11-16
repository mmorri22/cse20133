/*
 * In-Class Lecture 39 - Engine qualification harness.
 * You do not need to change this file.
 *
 * Every test compares the engine to the FP64 reference using the engine's
 * own stated tolerance, and checks a law of physics: a rotation never
 * changes a vector's length.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "engine.h"

enum { RANDOM_CASES = 1000 };

static double max_error = 0.0;
static double max_length_error = 0.0;
static int cases = 0;

/* Build a rotation from three angles (yaw, pitch, roll), in radians */
static void make_rotation(double yaw, double pitch, double roll, double R[DIM][DIM])
{
	const double cy = cos(yaw), sy = sin(yaw);
	const double cp = cos(pitch), sp = sin(pitch);
	const double cr = cos(roll), sr = sin(roll);
	R[0][0] = cy * cp;  R[0][1] = cy * sp * sr - sy * cr;  R[0][2] = cy * sp * cr + sy * sr;
	R[1][0] = sy * cp;  R[1][1] = sy * sp * sr + cy * cr;  R[1][2] = sy * sp * cr - cy * sr;
	R[2][0] = -sp;      R[2][1] = cp * sr;                 R[2][2] = cp * cr;
}

static double length(const double v[DIM])
{
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

/* Run one case and record the worst errors seen so far */
static void run_case(const double R[DIM][DIM], const double v[DIM])
{
	double expected[DIM];
	double actual[DIM];
	rotate_reference(R, v, expected);
	rotate(R, v, actual);

	for (int i = 0; i < DIM; i++) {
		double err = fabs(actual[i] - expected[i]);
		if (err > max_error) {
			max_error = err;
		}
	}
	double len_err = fabs(length(actual) - length(v));
	if (len_err > max_length_error) {
		max_length_error = len_err;
	}
	cases++;
}

static uint32_t rng_state = 1969U;

static double rand_angle(void)
{
	rng_state = rng_state * 1664525U + 1013904223U;
	return ((double)(rng_state >> 8) / 16777216.0 - 0.5) * 2.0 * 3.14159265358979;
}

int main(void)
{
	double R[DIM][DIM];
	const double pi = 3.14159265358979;

	fprintf(stdout, "Qualifying engine %s against the FP64 reference\n", ENGINE_NAME);
	fprintf(stdout, "Stated tolerance: %.1e\n\n", ENGINE_TOLERANCE);

	/* Edge cases: the identity, and 90-degree turns that put a vector
	 * exactly on an axis, where a component equals 1.0 */
	const double x_axis[DIM] = { 1.0, 0.0, 0.0 };
	const double diagonal[DIM] = { 0.57735, 0.57735, 0.57735 };
	make_rotation(0.0, 0.0, 0.0, R);
	run_case(R, x_axis);
	run_case(R, diagonal);
	make_rotation(pi / 2.0, 0.0, 0.0, R);
	run_case(R, x_axis);
	make_rotation(0.0, pi / 2.0, 0.0, R);
	run_case(R, x_axis);
	make_rotation(0.0, 0.0, pi / 2.0, R);
	run_case(R, diagonal);

	/* Random attitudes and random unit vectors */
	for (int c = 0; c < RANDOM_CASES; c++) {
		make_rotation(rand_angle(), rand_angle() / 2.0, rand_angle(), R);
		double v[DIM] = { rand_angle(), rand_angle(), rand_angle() };
		double len = length(v);
		if (len < 1.0e-6) {
			continue;
		}
		for (int i = 0; i < DIM; i++) {
			v[i] /= len;
		}
		run_case(R, v);
	}

	int accuracy_ok = (max_error <= ENGINE_TOLERANCE);
	int physics_ok = (max_length_error <= ENGINE_TOLERANCE);

	fprintf(stdout, "Cases run:                 %d\n", cases);
	fprintf(stdout, "Worst error vs reference:  %.3e   %s\n", max_error, accuracy_ok ? "PASS" : "FAIL");
	fprintf(stdout, "Worst change in length:    %.3e   %s\n", max_length_error, physics_ok ? "PASS" : "FAIL");
	fprintf(stdout, "\nENGINE %s: %s\n", ENGINE_NAME, (accuracy_ok && physics_ok) ? "QUALIFIED" : "NOT QUALIFIED");
	return (accuracy_ok && physics_ok) ? EXIT_SUCCESS : EXIT_FAILURE;
}
