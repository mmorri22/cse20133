#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Read the thruster temperature limit from a configuration file.
 * Returns 0 on success, -1 on failure. */
int load_limit(const char *filename, double *limit)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1;
	}
	int status = (fscanf(fp, "%lf", limit) == 1) ? 0 : -1;
	fclose(fp);
	return status;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <config_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	double max_temp = 0.0;

	/* Load the limit, and stop the program if loading fails */
	assert(load_limit(argv[1], &max_temp) == 0);

	const double reading = 285.0;
	fprintf(stdout, "Limit: %.1f C   Reading: %.1f C   ", max_temp, reading);
	if (reading > max_temp) {
		fprintf(stdout, "OVER LIMIT: shutting down thruster\n");
	}
	else {
		fprintf(stdout, "Nominal\n");
	}
	return EXIT_SUCCESS;
}
