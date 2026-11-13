#include <stdio.h>
#include <stdlib.h>

int main( const int argc, const char** argv ){

	if( argc != 2){
		fprintf( stdout, "Need exactly 2 inputs\n");
		return EXIT_FAILURE;
	}

	FILE* the_input = fopen( argv[1], "r" );

	if( the_input == NULL ){
		fprintf( stdout, "%s is not a valid file\n", argv[1] );
		return EXIT_FAILURE;
	}

	// Remember Dr. Morrison's Golden Rule of Pointers
	while( the_input != NULL ){

		char address[20];
		char word[20];
		char new_line_char;

		fprintf( stdout, "FILE pointers before scan: %p %p\n", the_input->_IO_read_ptr, the_input->_IO_read_end );

		// Read in the two strings and a new line char
		fscanf( the_input, "%s %s", address, word );

		// Must scan for new-line character
		fscanf( the_input, "%c", &new_line_char );

		// Print the contents to the user
		fprintf( stdout, "File Contents: %s %s\n", address, word );

		// Print the location of the two pointers
		fprintf( stdout, "FILE pointers after scan: %p %p\n", the_input->_IO_read_ptr, the_input->_IO_read_end );

		// If the FILE read pointer reaches the end of the FILE, break the while
		// Citation: https://code.woboq.org/userspace/glibc/libio/bits/types/struct_FILE.h.html#_IO_FILE
		if( the_input->_IO_read_ptr == the_input->_IO_read_end  )
			break;

	}

	fclose( the_input );

	return EXIT_SUCCESS;

}
