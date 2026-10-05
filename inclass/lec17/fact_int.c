#include <stdio.h>

int factorial( int fact_val );

int main( void ){

	// In lecture, run with 12 and then 13
	int value = 12;

	int factorial_result = factorial(value);

	fprintf( stdout, "%p %d %x\n", &factorial_result, factorial_result, factorial_result );

	return 0;
}

int factorial( int fact_val ){

	if(fact_val == 0)
		return 1;

	return fact_val * factorial (fact_val - 1);
}
