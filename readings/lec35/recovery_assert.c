#include <stdio.h>
#include <stdlib.h>

/* Holzmann's recovery assertion: print what failed and where, then
 * evaluate to false so the caller can take a recovery action.
 * Unlike assert(), it never stops the program and is never compiled out. */
#define c_assert(e) ((e) ? true : \
	(fprintf(stderr, "%s:%d: assertion failed: %s\n", __FILE__, __LINE__, #e), false))

#define MAX_READINGS 8
#define OK 0
#define ERR_PARAM -1

/* Average the first count readings. Returns OK or ERR_PARAM. */
int average_temp(const double readings[], int count, double *average)
{
	if (!c_assert(readings != NULL) || !c_assert(average != NULL)) {
		return ERR_PARAM;
	}
	if (!c_assert(count > 0 && count <= MAX_READINGS)) {
		return ERR_PARAM;
	}

	double sum = 0.0;
	for (int i = 0; i < count; i++) {
		sum += readings[i];
	}
	*average = sum / count;
	return OK;
}

int main(void)
{
	const double readings[MAX_READINGS] = { 281.0, 283.5, 284.0, 282.5, 0.0, 0.0, 0.0, 0.0 };
	double average = 0.0;

	/* A good call */
	if (average_temp(readings, 4, &average) == OK) {
		fprintf(stdout, "Average of 4 readings: %.2f C\n", average);
	}

	/* A corrupted count: the assertion fails, and the caller recovers */
	if (average_temp(readings, 4000, &average) != OK) {
		fprintf(stdout, "Bad reading count. Using last known good average: %.2f C\n", average);
	}

	fprintf(stdout, "Still running.\n");
	return EXIT_SUCCESS;
}
