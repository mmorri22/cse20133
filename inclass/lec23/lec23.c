#include "sllist.h"


int main( const int argc, const char* argv[] ){

	fprintf( stdout, "argc: %p %d\n", &argc, argc );
	fprintf( stdout, "argv: %p %p\n", &argv, argv );

	int iter;
	for( iter = 0; iter < argc; ++iter ){

		fprintf( stdout, "argv[%d]: %p %p %s\n", iter, &argv[iter], argv[iter], argv[iter] );
	}


	// Step 4 - Dynamically allocate a sllist
	sllist* the_list = (sllist *)malloc( sizeof( sllist ) );

	// Step 4-1 - Set the head_node to NULL
	the_list->head_node = NULL;

	fprintf( stdout, "Base Addresses: %p %p\n", &the_list, the_list );

	// Step 11 - Replace 7 - Call insert with as many as we want to insert
	for( iter = 1; iter < argc; ++iter ){

		int the_value = atoi( argv[iter] );

		insert( the_list, the_value );

	}


	// Step 9 - Call in main
	fprintf( stdout, "Head Node Addresses: %p %p\n", &(the_list->head_node), the_list->head_node );
	print_list( the_list->head_node );


	// Step 11 - Call the destructor
	destructor( the_list->head_node );


	// Step 5 - Free the sllist
	free( the_list );

	return EXIT_SUCCESS;
}
