#include <stdio.h>
#include <stdlib.h>

#define LUI long unsigned int

LUI Fibonacci( LUI fib_num, LUI* fib_array );

void print_array ( LUI fib_num, LUI* fib_array );

int main( void ){

	LUI fib_num;

	fprintf(stdout, "Enter the fib num to solve: ");

	if( fscanf( stdin, "%lu", &fib_num) == -1 ){
		return EXIT_FAILURE;
	}

	LUI* fib_array = (LUI*)malloc( fib_num * sizeof(LUI) );

	Fibonacci( fib_num, fib_array );

	print_array ( fib_num, fib_array );

	free(fib_array);

	return EXIT_SUCCESS;

}


LUI Fibonacci( LUI fib_num, LUI* fib_array ){

	if( fib_array[fib_num] != 0 ){
		return fib_array[fib_num];
	}

	if( fib_num == 0 || fib_num == 1 ){
		fib_array[fib_num] = 1;

		return 1;
	}

	fib_array[fib_num] = Fibonacci( fib_num - 1, fib_array ) + Fibonacci( fib_num - 2, fib_array );

	return fib_array[fib_num];
}

void print_array ( LUI fib_num, LUI* fib_array ){

	fprintf( stdout, "The fibonacci values: " );

	LUI iter;
	for( iter = 0; iter < fib_num; ++iter ){

		fprintf( stdout, "%lu ", fib_array[iter] );

	}
	fprintf( stdout, "\n" );

}