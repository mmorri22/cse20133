#include <stdio.h>

int main( void ){

	long unsigned int gangnam_count = 2147483647;

	fprintf( stdout, "Initial: %lu %lx\n", gangnam_count, gangnam_count );

	++gangnam_count;

	fprintf( stdout, "Final  : %lu %lx\n", gangnam_count, gangnam_count );

	return 0;

}

