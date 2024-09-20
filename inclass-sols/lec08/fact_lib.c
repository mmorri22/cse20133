#include "fact_lib.h"

/********************************************
* Function Name  : factorial
* Pre-conditions : int num
* Post-conditions: double
* 
* Takes in an int between 0 and 170, and returns
* the factorial value. Returns -1 if those values 
* are exceeded 
********************************************/
double factorial(int num){

	// 0! is 1
	if(num == 0)
		return 1;

	double result = 1;
	while(num > 0){

		result *= (double)num;
		num--;

	}

	return result;
}


void printFactorial( int num, double result ){
	
	fprintf(stdout, "Value of %d! is %le. Hex is %a\n", num, result, result);
}
