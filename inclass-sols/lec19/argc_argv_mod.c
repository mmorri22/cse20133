#include <stdio.h>
#include <stdlib.h>

void print_inputs( const int argc, const char* argv[] ){

	fprintf( stdout, "argc = %d\n", argc );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d] = %s\tat %p\n",
				iter, argv[iter], &argv[iter] );

	}

}

int main( const int argc, const char* argv[] ){

	fprintf( stdout, "Initial argc: %d\n", argc );

	print_inputs( argc, argv );

	// We will change this to 5, 25, 29, and 30
	// Will not be a compiler error since we have added "const"
	argc += 32;

	print_inputs( argc, argv );

	return 0;
}
