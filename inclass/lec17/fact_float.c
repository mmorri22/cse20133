#include <stdio.h>

float factorial( float fact_val );

int main( void ){

	// In lecture, run with 21 and then 34 and then 35
	float value = (float)35;

	float factorial_result = factorial(value);

	fprintf( stdout, "%p %f %a\n", &factorial_result, factorial_result, factorial_result );

	return 0;
}

float factorial( float fact_val ){

	if(fact_val <= 0)
		return 1;

	return fact_val * factorial (fact_val - 1);
}
