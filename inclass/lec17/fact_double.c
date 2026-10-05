#include <stdio.h>

int main( void ){

	unsigned int time; 
	// unsigned int value = 170;
	unsigned int value = 171;
	double factorial = 1;

	for( time = 1; time <= value; ++time ){
	
		factorial *= (double)time;

		fprintf( stdout, "%p %le %la\n", &factorial, factorial, factorial );

	}

	return 0;
}
