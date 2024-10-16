#include "sllist_sol.h"


sllist* constructor(){

    sllist* temp_node = (sllist *)malloc( sizeof(sllist) );

	temp_node->head_node = NULL;

    return temp_node;

}


// Create the constructor method for sllist
void push( sllist* the_list, int the_value ){

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

	// Set the head node equal to the insert node
	the_list->head_node = insert_node;

	// Set the head node's next_node equal to curr_ptr
	the_list->head_node->next_node = curr_ptr;
	
}

void pop( sllist* the_list ){

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the head node is not empty
	if(the_list->head_node != NULL ){

		// Set a temp node equal to the current head node
		sll_node* temp_node = the_list->head_node;

		// Set the head node equal to the head node's next node
		the_list->head_node = temp_node->next_node;

		// Free the temp pointer
		free(temp_node);

		return;
	}

	// If the head node is empty, print a message that the list is empty
	fprintf( stdout, "Can't pop. List is empty\n");
}




// Step 8 - Print the Singly Linked List
void print_list( sll_node* curr_ptr ){

	if( curr_ptr != NULL ){

		fprintf( stdout, "Addr: %p, ", curr_ptr );
		fprintf( stdout, "Data: %d, ", curr_ptr->data );
		fprintf( stdout, "next_node Addr: %p, ", &(curr_ptr->next_node) );
		fprintf( stdout, "next_node Data: %p\n", curr_ptr->next_node );
		fprintf( stdout, "\n" );

		// Iterate through the next node
		print_list( curr_ptr->next_node );

	}

}


// Free all the elements
void destructor( sll_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	// Recursively call destructor on the next node
	if( curr_ptr != NULL ){
		destructor(curr_ptr->next_node);

		// Free the current pointer
		free(curr_ptr);
	}

}
