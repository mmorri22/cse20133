#include <stdio.h>

long unsigned int factorial( long unsigned int fact_val );

int main( void ){

	// In lecture, run with 13 and then 20 and then 21
	long unsigned int value = 20;

	long unsigned int factorial_result = factorial(value);

	fprintf( stdout, "%p %lu %lx\n", &factorial_result, factorial_result, factorial_result );

	return 0;
}

long unsigned int factorial( long unsigned int fact_val ){

	if(fact_val == 0)
		return 1;

	return fact_val * factorial (fact_val - 1);
}
