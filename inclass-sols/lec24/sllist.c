#include "sllist.h"


sllist* constructor(){

    sllist* temp_node = (sllist *)malloc( sizeof(sllist) );

	temp_node->head_node = NULL;

    return temp_node;

}


// Create the constructor method for sllist
void push( sllist* the_list, int the_value ){

	// Create a sll_node pointer called insert_node
	

	// Set the insert_node's data to the_value and next_node to NULL
	
	

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the list is empty
	

		// Set the head node equal to insert_node
		

		// And return
		
	

	// Otherwise, create a curr_ptr equal to the head_node
	

	// Set the head node equal to the insert node
	

	// Set the head node's next_node equal to curr_ptr
	
	
}

void pop( sllist* the_list ){

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the head node is not empty
	

		// Set a temp node equal to the current head node
		

		// Set the head node equal to the head node's next node
		

		// Free the temp pointer
		

		return;
	}

	// If the head node is empty, print a message that the list is empty
	fprintf( stdout, "Can't pop. List is empty\n");
}


// Step 8 - Print the Singly Linked List
void print_list( sll_node* head_node ){

	// Just change node_0 to head_node
	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){

		fprintf( stdout, "Address: %p, ", curr_ptr );
		fprintf( stdout, "Value: %d, ", curr_ptr->data );
		fprintf( stdout, "next_node Addr: %p, ", &(curr_ptr->next_node) );
		fprintf( stdout, "next_node Value: %p\n", curr_ptr->next_node );

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}


// Free all the elements
void destructor( sll_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( /* Delete this comment */ ){
		
		// Recursively call destructor on the next node

		// Free the current pointer
		
	}

}
