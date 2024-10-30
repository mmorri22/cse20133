#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node{

	int data;
	struct stack_node* next_node;

}stack_node;

// Step 3 - Create the struct for stack
typedef struct stack{

	// Stack Number for Printing
	int stack_num;

	// Make the private stack_node member called head_node
	struct stack_node* head_node;

}stack;


stack* constructor();

// Step 6 - Create the constructor method for stack
void push( stack* the_list, int the_value );


// Step 6 - Create the constructor method for stack
void pop( stack* the_list );


// Step 8 - Print the Singly Linked List
void print_list( stack_node* head_node );


void print_stack( stack_node* head_node );

// Step 10 - Free all the elements
void destructor( stack_node* curr_ptr );

#endif
