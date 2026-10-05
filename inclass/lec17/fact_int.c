#include <stdio.h>

int main( void ){

	int iter;
	// In lecture, run with 13 and then comment 13 and uncomment 14
	//int value = 15; 
	int value = 20;
	int factorial = 1;

	for( iter = 1; iter <= value; ++iter ){
	
		factorial *= iter;

		fprintf( stdout, "%p %d %x\n", &factorial, factorial, factorial );

	}

	return 0;
}
