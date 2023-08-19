#include <stdio.h>

/* Function Declarations */
double findAverage( double number1, double number2 );

void printAverage(  double number1, double number2, double average );

/* Main Function */
int main( void ){
	
	double x = 1.1, y = 1.2;
	
	/* double average = findAverage( x, y ); */
	
	printAverage( x, y, findAverage( x, y ) );
	
	return 0;
}

/* Function Definitions */
double findAverage( double number1, double number2 ){
	
	return ( number1 + number2 ) / 2;
	
}

void printAverage(  double number1, double number2, double average ){
	
	fprintf( stdout, "The average of %lf and %lf is %lf\n", number1, number2, average );
}
