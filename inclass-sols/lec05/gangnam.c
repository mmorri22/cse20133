#include <stdio.h>

int main( void ){

	int gangnam_count = 2147483647;

	fprintf( stdout, "Initial: %d %x\n", gangnam_count, gangnam_count );

	++gangnam_count;

	fprintf( stdout, "Final  : %d %x\n", gangnam_count, gangnam_count );

	return 0;

}
