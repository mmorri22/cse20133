#include <stdio.h>

int main( void ){

	/* Create Variable */
	int maximum_effort;

	/* for Loop Statement */
	for( maximum_effort = 10; maximum_effort < 100; maximum_effort += 10){
		fprintf(stdout, "Effort is %d Keep going!\n", maximum_effort);
	}
	fprintf(stdout, "Congratulations, you've crushed the assignment!\n");

	return 0;
}
