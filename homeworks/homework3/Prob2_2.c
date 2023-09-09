#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* No need to modify */
int rand_int(){

	int ret = rand();

	return ret % 10;

}

/* Modify this function here */
int sample_geometric_rv( int p ){

	srand( (unsigned int)time(0) );	

	int q = p - 1;

	int n = 0;

	do{
		q = rand_int();
		++n;

		fprintf( stdout, "%d %d\n", q, p );
	
	// For this example, we are fine comparring doubles
	// The == comparison is the tough one
	}while( q >= p );

	return n;

}


int main( void ){

	int input = 2;

	fprintf( stdout, "%d\n", sample_geometric_rv(input) );

	return 0;

}
