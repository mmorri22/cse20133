#include <stdio.h>
#include <stdlib.h>

#define NUM_READINGS 16

/* Read up to NUM_READINGS temperatures from a file and return their average. */
double average_temp(const char *filename)
{
	double *readings = (double *)malloc(NUM_READINGS * sizeof(double));

	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1.0;	/* early exit: what happened to readings? */
	}

	int count = 0;
	while (count < NUM_READINGS && fscanf(fp, "%lf", &readings[count]) == 1) {
		count++;
	}
	fclose(fp);

	double sum = 0.0;
	for (int i = 0; i < count; i++) {
		sum += readings[i];
	}
	free(readings);

	return (count > 0) ? sum / count : 0.0;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(-1);
	}
	fprintf(stdout, "Average: %.2f\n", average_temp(argv[1]));
	return 0;
}
