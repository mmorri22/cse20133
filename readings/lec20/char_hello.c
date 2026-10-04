#include <stdio.h>
#include <stdlib.h>

int main(void){

	/* Allocate the memory */
	long unsigned int size = 13 * sizeof(char);

	/* New Version of casting */
	char* hello = (char *)malloc( size );

	/* Printing the base address */
	fprintf( stdout, "size location                 : %p\n", &size);
	fprintf( stdout, "Working Memory (Register)     : %p\n", &hello );
	fprintf( stdout, "Long-term Memory (Data Memory): %p\n", hello );

	/* Allocate the characters using ASCII*/
	hello[0] = 'H';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 'o';
	hello[5] = ',';
	hello[6] = ' ';
	hello[7] = 'W';
	hello[8] = 'o';
	hello[9] = 'r';
	hello[10] = 'l';
	hello[11] = 'd';
	hello[12] = '!';

	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		fprintf( stdout, "hello[%2ld] = %c at %p\n", iter, hello[iter], &hello[iter] );
	}

	/* Free the memory */
	free( hello );

	return 0;
}
