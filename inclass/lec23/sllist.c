#include "sllist.h"


// Step 6 - Create the constructor method for sllist
void insert( sllist* the_list, int the_value ){

	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );

	// Set the insert_node's data to the_value and next_node to NULL
	insert_node->data = the_value;
	insert_node->next_node = NULL;

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the list is empty
	if( the_list->head_node == NULL ){

		// Set the head node equal to insert_node
		the_list->head_node = insert_node;

		// And return
		return;
	}

	// Otherwise, create a curr_ptr equal to the head_node
	sll_node* curr_ptr = the_list->head_node;

	// Iterate until the next_node is NULL
	while( curr_ptr->next_node != NULL ){

		curr_ptr = curr_ptr->next_node;
	}

	// Set curr_ptr's next_node equal to insert_node
	curr_ptr->next_node = insert_node;

}


// Step 8 - Print the Singly Linked List
void print_list( sll_node* head_node ){

	// Just change node_0 to head_node

	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){

		fprintf( stdout, "Node Base Address: %p, ", curr_ptr );
		fprintf( stdout, "Data Value: %d, ", curr_ptr->data );
		fprintf( stdout, "Location of Next Node: %p, ", &(curr_ptr->next_node) );
		fprintf( stdout, "Value of Next Node: %p\n", curr_ptr->next_node );

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}


// Step 10 - Free all the elements
void destructor( sll_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( curr_ptr == NULL )
		return;


	// Recursively call destructor on the next node
	destructor( curr_ptr->next_node );

	// Free the current pointer
	free( curr_ptr );

}

#endif
