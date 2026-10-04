#include <stdio.h>
#include <stdlib.h>

int main(void){

	/* Allocate the memory */
	long unsigned int size = 13 * sizeof(char);
	void* hello = malloc( size );

	/* Printing the base address */
	fprintf( stdout, "Working Memory (Register)     : %p\n", &hello );
	fprintf( stdout, "Long-term Memory (Data Memory): %p\n", hello );

	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		fprintf( stdout, "address of hello[%ld] = %p\n", iter, hello + iter*sizeof(char) );
	}

	/* Free the memory */
	free( hello );

	return 0;
}
