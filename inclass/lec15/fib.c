#include <stdio.h>
#include <stdlib.h>

int Fibonacci( int fib_num );

int main( void ){

	/* We will change this to 42 and see how it works */
	int fib_num = 6;

	fprintf( stdout, "The %d Fib Number is = %d\n", fib_num, Fibonacci( fib_num - 1 ) );

	return EXIT_SUCCESS;

}

int Fibonacci( int fib_num ){

	if( fib_num == 0 )
		return 1;

	if( fib_num == 1 )
		return 1;

	return Fibonacci( fib_num - 1 ) + Fibonacci( fib_num - 2 );

}
