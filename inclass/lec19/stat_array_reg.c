#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 1000000


void fibonacci()
{

	unsigned int results_buffer[NMAX];

	register unsigned int first_num = 1;

	register unsigned int second_num = 1;

	register unsigned int third_num; // No need to re-allocate ever loop

	register long unsigned int iter;
	for (iter = 2; iter < NMAX; iter++) {

		third_num = first_num + second_num;

		results_buffer[ iter ] = third_num;

		first_num = second_num;

		second_num = third_num;
	}

}

int main(void) {

	/* Run 100,000 tests */
	long unsigned int num_tests = 1000;

	/* clock_t is a type from #include <time.h> */
	/* clock_t is equivalent to a 64-bit signed integer */
	/* We start the profiling */
	clock_t time_start = clock();

	// Allocate the memory once

	long unsigned int iter;
	for (iter = 0; iter < num_tests; ++iter)
		fibonacci();

	/* Obtain the end time and complete the time profile */
	clock_t time_end = clock();

	/* compute average execution time */
	clock_t time_run = time_end - time_start;
	long unsigned int num_clk_pulses = CLOCKS_PER_SEC*num_tests;

	/* To obtain the average in an efficient manner */
	/* Type cast BOTH long ints to a double and then store */
	double final_avg = (double)(time_run) / (double)(num_clk_pulses) ;

	/* print avg execution time in milliseconds */
	fprintf( stdout, "Total Clock Pulses: %ld\n", time_run );
	fprintf( stdout, "Avg. execution time: %lf sec\n", final_avg);

	return 0;
}
