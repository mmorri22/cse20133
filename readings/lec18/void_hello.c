#include <stdio.h>
#include <stdlib.h>

int main(void){

	/* Allocate the memory */
	long unsigned int size = 13 * sizeof(char);
	void* hello = malloc( size );

	/* Printing the base address */
	fprintf( stdout, "size location                 : %p\n", &size);
	fprintf( stdout, "Working Memory (Register)     : %p\n", &hello );
	fprintf( stdout, "Long-term Memory (Data Memory): %p\n", hello );

	/* Allocate the characters using ASCII*/
	*((char *)(hello + 0*sizeof(char))) = 0x48;	// 'H'
	*((char *)(hello + 1*sizeof(char))) = 0x65;	// 'e'
	*((char *)(hello + 2*sizeof(char))) = 0x6c;	// 'l'
	*((char *)(hello + 3*sizeof(char))) = 0x6c;	// 'l'
	*((char *)(hello + 4*sizeof(char))) = 0x6f;	// 'o'
	*((char *)(hello + 5*sizeof(char))) = 0x2c;	// ','
	*((char *)(hello + 6*sizeof(char))) = 0x20;	// ' '
	*((char *)(hello + 7*sizeof(char))) = 0x57;	// 'W'
	*((char *)(hello + 8*sizeof(char))) = 0x6f;	// 'o'
	*((char *)(hello + 9*sizeof(char))) = 0x72;	// 'r'
	*((char *)(hello + 10*sizeof(char))) = 0x6c;	// 'l'
	*((char *)(hello + 11*sizeof(char))) = 0x64;	// 'd'
	*((char *)(hello + 12*sizeof(char))) = 0x21;	// '!'

	long unsigned int iter;
	for( iter = 0; iter < size; ++iter ){
		fprintf( stdout, "hello[%2ld] = %c at %p\n",
			iter, *((char *)(hello + iter*sizeof(char))), hello + iter*sizeof(char) );
	}

	/* Free the memory */
	free( hello );

	return 0;
}
