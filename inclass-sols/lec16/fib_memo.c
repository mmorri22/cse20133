#include <stdio.h>
#include <stdlib.h>

int fibonacci( long unsigned int fib_num, int* fib_array );

void print_array ( long unsigned int fib_num, int* fib_array );

int main( void ){



	return EXIT_SUCCESS;

}


int Fibonacci( long unsigned int fib_num, int* fib_array ){



}

void print_array ( long unsigned int fib_num, int* fib_array ){

	fprintf( stdout, "The fibonacci values: " );

	long unsigned int iter;
	for( iter = 0; iter < fib_num; ++iter ){

		fprintf( stdout, "%d ", fib_array[iter] );

	}
	fprintf( stdout, "\n" );

}
