#include <stdio.h>
#include <stdlib.h>

/* Modify Compiler Directive to update value */
#define FIB_NUM 6

/* Step 2a - Modify the function declaration to take in the array */
int Fibonacci( int fib_num, int fib_array[] );

void print_array ( int fib_num, int fib_array[] );

int main( void ){

	/* Step 1 - Initialize a static array of fib_num size */
	/* Step 7 - We have a modification to make here... */
	int fib_array[FIB_NUM] = { [0 ... (FIB_NUM-1)] = 0 };

	fprintf( stdout, "The %d Fib Number is = %d\n", FIB_NUM, Fibonacci( FIB_NUM - 1, fib_array ) );

	print_array( FIB_NUM, fib_array );

	return EXIT_SUCCESS;

}

/* Step 2b - Modify the Fibonacci Function to take in the array */
int Fibonacci( int fib_num, int fib_array[] ){

	/* Step 3 - Check the array value */
	if( fib_array[ fib_num ] != 0 ){
		return fib_array[ fib_num ];
	}

	/* Step 4 - Set the array value to 1 if fib_num is 0 or 1 */
	if( fib_num == 0 || fib_num == 1){
		fib_array[ fib_num ] = 1;
	}

	/* Step 5 - Update the array with the binary conversion */
	else{
		fib_array[ fib_num ] = Fibonacci( fib_num - 1, fib_array ) + Fibonacci( fib_num - 2, fib_array );
	}

	/* Step 6 - Return the array value */
	return fib_array[ fib_num ];

}

void print_array ( int fib_num, int fib_array[] ){

	fprintf( stdout, "The fibonacci values: " );

	int iter;
	for( iter = 0; iter < fib_num; ++iter ){

		fprintf( stdout, "%d ", fib_array[iter] );

	}
	fprintf( stdout, "\n" );

}
