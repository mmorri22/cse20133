#include <stdio.h>

int Fibonacci( int fib_num );

int main( const int argc, const char* argv[] ){

	int fib_num = 5;

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
