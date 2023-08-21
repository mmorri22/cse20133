/**********************************************
* File: squareFunc.c
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains two functions for summing 
* an integer, and is used in lecture to demonstrate
* how the stack and variables work 
**********************************************/
#include <stdio.h>

int total; // Global variable

/* Function Declarations */
int Square(int x);

int SumOfSquare(int x, int y);

/* Main function */
int main(void){
	int x = 3, y = 4;
	total = SumOfSquare(x, y);
	fprintf(stdout, "The square of the sum of %d and %d is %d\n", x, y, total);
	return 0;
}

/* Function Definitions */
int Square(int x){
	x = x * x;
	return x;
}

int SumOfSquare(int x, int y){
	int z = Square(x + y);
	return z;
}
