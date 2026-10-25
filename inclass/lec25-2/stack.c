#include "stack.h"


stack* constructor(){

    stack* temp_node = (stack *)malloc( sizeof(stack) );

	temp_node->head_node = NULL;

    return temp_node;

}


// Create the constructor method for stack
void push( stack* the_list, int the_value ){

	// Create a stack_node pointer called insert_node
	stack_node* insert_node = (stack_node *)malloc( sizeof(stack_node) );

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
	stack_node* curr_ptr = the_list->head_node;

	// Set the head node equal to the insert node
	the_list->head_node = insert_node;

	// Set the head node's next_node equal to curr_ptr
	the_list->head_node->next_node = curr_ptr;
	
}

void pop( stack* the_list ){

	// Dr. Morrison's Golden Rule of Pointers
	// Check if the head node is not empty
	if(the_list->head_node != NULL){

		// Set a temp node equal to the current head node
		stack_node* temp_node = the_list->head_node;

		// Set the head node equal to the head node's next node
		the_list->head_node = temp_node->next_node;

		// Free the temp pointer
		free(temp_node);

		return;
	}

	// If the head node is empty, print a message that the list is empty
	fprintf( stdout, "Can't pop. List is empty\n");
}

// Print the Singly Linked List 
void print_stack( stack_node* head_node ){

	stack_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Only print the value
		fprintf( stdout, "%d ", curr_ptr->data );		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}	


// Step 8 - Print the Singly Linked List
void print_list( stack_node* head_node ){

	// Just change node_0 to head_node
	stack_node* curr_ptr = head_node;
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
void destructor( stack_node* curr_ptr ){

	// Dr. Morrison's Golden Rule of Pointers
	if( curr_ptr != NULL ){
		
		// Recursively call destructor on the next node
		destructor( curr_ptr->next_node );
		// Free the current pointer
		free(curr_ptr);
	}

}
