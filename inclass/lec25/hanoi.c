#include "stack.h"
#include "hanoi_func.h"

int main( const int argc, const char* argv[] ){


	if( argc != 2 ){
		
		fprintf( stdout, "Incorrect number of inputs\n " );
		exit(-1);
		
	}
	
	// Get the Stack Size 
	int stack_size = atoi( argv[1] );
	
	// Track the number of moves 
	int num_moves = 0;
	
	// Dynamically allocate three stacks  
	stack* tower_1 = (stack *)malloc( sizeof( stack ) );
	stack* tower_2 = (stack *)malloc( sizeof( stack ) );
	stack* tower_3 = (stack *)malloc( sizeof( stack ) );
	
	// Set the head_node to NULL 
	tower_1->head_node = NULL;
	tower_1->stack_num = 1;
	tower_2->head_node = NULL;
	tower_2->stack_num = 2;
	tower_3->head_node = NULL;
	tower_3->stack_num = 3;
	
	// Insert elements in reverse
	int iter;
	for( iter = stack_size; iter > 0; --iter ){
		
		push( tower_1, iter );
		
	}
	
	// Run the algorithm
	hanoi( stack_size, tower_1, tower_2, tower_3, &num_moves );
	
	fprintf( stdout, "%d  plates moved in %d moves\n" , stack_size, num_moves );

	
	// Step 11 - Call the destructors
	destructor( tower_3->head_node );
	destructor( tower_2->head_node );
	destructor( tower_1->head_node );

	
	// Step 5 - Free the stacks 
	free( tower_3 );
	free( tower_2 );
	free( tower_1 );
	
	return EXIT_SUCCESS;
}