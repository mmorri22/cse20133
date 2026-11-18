/*
 * In-Class Lecture 32 - Flight Software Code Review
 *
 * This program processes thruster nozzle temperature telemetry.
 *   - Line 1 of the input file is the number of readings the instrument reports
 *   - The remaining lines are temperatures in degrees Celsius
 *
 * The program computes the average and maximum temperature, then packs the
 * average into a 16-bit telemetry field in hundredths of a degree, the same
 * way a real downlink packet saves bandwidth.
 *
 * It compiles cleanly with every course flag, and it prints the right answer
 * on nominal.txt. It still has four bugs. Your job is to find them with the
 * tools from Reading 32-2, fix them, and log which tool caught each one.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_READINGS 8

/* Process one telemetry file. Returns EXIT_SUCCESS or EXIT_FAILURE. */
int process_telemetry(const char *filename)
{
	// Open the telemetry file and check that it exists
	FILE *tlm_file = fopen(filename, "r");
	if (tlm_file == NULL) {
		fprintf(stderr, "The file %s does not exist\n", filename);
		return EXIT_FAILURE;
	}

	// Read the number of readings the instrument reports
	long unsigned int num_readings = 0;
	if (fscanf(tlm_file, "%lu", &num_readings) != 1) {
		fprintf(stderr, "Could not read the number of readings\n");
		fclose(tlm_file);
		return EXIT_FAILURE;
	}

	// Reject a reading count the buffer cannot hold
	if (num_readings < 1 || num_readings > MAX_READINGS) {
		fprintf(stderr, "Invalid number of readings: %lu\n", num_readings);
		fclose(tlm_file);
		return EXIT_FAILURE;
	}

	// Allocate space for the readings
	double *readings = (double *)malloc(MAX_READINGS * sizeof(double));
	if (readings == NULL) {
		free(readings);
		fclose(tlm_file);
		return EXIT_FAILURE;
	}

	// Read every temperature in the file
	long unsigned int count = 0;
	while (count < num_readings && fscanf(tlm_file, "%lf", &readings[count]) == 1) {
		count++;
	}
	fclose(tlm_file);

	if (count == 0) {
	    fprintf(stderr, "No readings in %s\n", filename);
	    free(readings);
	    return EXIT_FAILURE;
	}
	if (count != num_readings) {
	    fprintf(stderr, "ANOMALY: %lu readings reported, %lu read\n", num_readings, count);
	}

	// Compute the average and the maximum over the reported readings
	double sum = 0.0;
	double max_temp = -273.15;
	for (long unsigned int i = 0; i < count; i++) {
		sum += readings[i];
		if (readings[i] > max_temp) {
			max_temp = readings[i];
		}
	}
	double average = sum / (double)count;

	// Pack the average into the 16-bit telemetry field (hundredths of a degree)
	double scaled = average * 100.0;
	int16_t packed_avg;
	if (scaled > INT16_MAX) {
	    fprintf(stderr, "ANOMALY: average %.2f C exceeds the telemetry field; saturating\n", average);
	    packed_avg = INT16_MAX;
	}
	else if (scaled < INT16_MIN) {
	    fprintf(stderr, "ANOMALY: average %.2f C is below the telemetry field; saturating\n", average);
	    packed_avg = INT16_MIN;
	}
	else {
	    packed_avg = (int16_t)scaled;
	}

	fprintf(stdout, "Readings:      %lu reported, %lu read\n", num_readings, count);
	fprintf(stdout, "Average:       %.2f C\n", average);
	fprintf(stdout, "Maximum:       %.2f C\n", max_temp);
	fprintf(stdout, "Packed field:  %d (decodes to %.2f C)\n", packed_avg, packed_avg / 100.0);

	free(readings);
	return EXIT_SUCCESS;
}

int main(const int argc, const char *argv[])
{
	// Protect the inputs
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <telemetry_file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	return process_telemetry(argv[1]);
}
