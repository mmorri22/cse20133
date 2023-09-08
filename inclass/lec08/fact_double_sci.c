/**********************************************
* File: factDoubleSci.c
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains an introductory example of 
* function prototypes and definitions
*
* Modifies factDouble.c by changing the output specifier
* in printFactorial to %le, allowing for easier readability
**********************************************/

#include "stdio.h"
#include "stdlib.h" // Included for exit 

/* Function Prototypes */
double factorial(int num);

void printFactorial( int num, double result );

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
