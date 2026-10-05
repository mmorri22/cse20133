#include <stdio.h>

double factorial( double fact_val );

int main( void ){

	// In lecture, run with 35 and then 170 and then 171
	double value = 35;

	double factorial_result = factorial(value);

	fprintf( stdout, "%p %f %a\n", &factorial_result, factorial_result, factorial_result );

	return 0;
}

double factorial( double fact_val ){

	if(fact_val <= 0)
		return 1;

	return fact_val * factorial (fact_val - 1);
}
