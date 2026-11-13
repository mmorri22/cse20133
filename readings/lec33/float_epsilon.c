#include <stdio.h>
#include <float.h>

/*
 * Find the smallest power of two that still changes 1.0f when added to it.
 * Below that value, 1.0f + eps rounds back to exactly 1.0f.
 */
int main(void)
{
	volatile float eps = 1.0f;	/* volatile: force a real 32-bit store each time */
	volatile float test = 2.0f;
	int halvings = 0;

	while (test != 1.0f) {
		eps = eps / 2.0f;
		test = 1.0f + eps;
		halvings++;
	}

	/* The loop stops one step too far: eps is now too small to matter */
	float machine_eps = eps * 2.0f;

	fprintf(stdout, "Halvings:           %d\n", halvings);
	fprintf(stdout, "Measured epsilon:   %.10e\n", (double)machine_eps);
	fprintf(stdout, "FLT_EPSILON:        %.10e\n", (double)FLT_EPSILON);
	return 0;
}
