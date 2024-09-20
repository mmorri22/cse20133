#include "fact_lib.h"

/* main function */
int main(void){
	
	for( int num = 34; num <= 175; num++ ){

		/* Get the result */
		double result = factorial(num);
	
		/* Print Results */
		printFactorial( num, result );
		
	}

	return 0;
}