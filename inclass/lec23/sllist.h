#ifndef SLLIST_H
#define SLLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

	int data;
	struct sll_node* next_node;

}sll_node;

// Step 3 - Create the struct for sllist
typedef struct sllist{

	// Make the private sll_node member called head_node
	struct sll_node* head_node;

}sllist;


sllist* constructor();

// Step 6 - Create the constructor method for sllist
void push( sllist* the_list, int the_value );


// Step 6 - Create the constructor method for sllist
void pop( sllist* the_list );


// Step 8 - Print the Singly Linked List
void print_list( sll_node* head_node );


// Step 10 - Free all the elements
void destructor( sll_node* curr_ptr );

#endif
