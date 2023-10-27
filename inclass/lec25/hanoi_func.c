#include "hanoi_func.h"

void move(stack* source, stack* destination, int* numMoves){

	// De-reference and Increment the number of moves
	(*numMoves)++;

	// Get the data from the head node, and push on the destination
	push( destination, source->head_node->data );

	// Remove the element from the source
	pop( source );

	// Print the results
	fprintf( stdout, "Move %d: %d from stack %d to stack%d\n",
		*numMoves, destination->head_node->data,
		source->stack_num, destination->stack_num);

}


void hanoi( int n, stack* source, stack* destination, stack* auxillary, int* numMoves){


	

}
