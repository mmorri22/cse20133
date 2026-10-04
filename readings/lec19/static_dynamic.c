#include <stdio.h>
#include <stdlib.h>

int main(){

	/* Static Memory Allocation */
	int int_static[] = {10, 20, -19, 34};

	/* Dynamic Memory Allocation */
	long unsigned int length = 4;
	int* int_dynamic = (int *)malloc( length * sizeof(int) );

	/* Dynamic Memory Data Storage */
	int_dynamic[0] = 10;
	int_dynamic[1] = 20;
	int_dynamic[2] = -19;
	int_dynamic[3] = 34;

	/* Base Address information */
	fprintf( stdout, "Static Memory address: %p\n", int_static );
	fprintf( stdout, "Dynamic Memory addresses: %p %p\n", &int_dynamic, int_dynamic );

	/* Print the data addresses for static and dynamic*/
	long unsigned int iter;
	for( iter = 0; iter < length; ++iter ){

		fprintf( stdout, "int_static[%lu] = %d at %p and int_dynamic[%lu] = %d at %p\n",
			iter, int_static[iter], &int_static[iter], iter, int_dynamic[iter], &int_dynamic[iter] );
	}

	// Free dynamically allocated memory
	free( int_dynamic );

	// Do NOT free statically allocated memory- The OS does this automatically!
	// free( int_static );

	return 0;

}
