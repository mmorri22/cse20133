#include <stdio.h>

int main( void ){

	/* Create Variable */
	int maximum_effort = 10;

	/* While Loop Statement */
	while(maximum_effort < 100){
		fprintf(stdout, "Effort is %d Keep going!\n", maximum_effort);
		maximum_effort += 10;
	}
	fprintf(stdout, "Congratulations, you've crushed the assignment!\n");

	return 0;
}
