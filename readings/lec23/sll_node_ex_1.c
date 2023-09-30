#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node{

    int data;
    struct sll_node* next_node;    

}sll_node;


int main( void ){

    // Create four sll_nodes with dynamic memory allocation
    sll_node* node_0 = (sll_node*)malloc( sizeof(sll_node) );
    sll_node* node_1 = (sll_node*)malloc( sizeof(sll_node) );
    sll_node* node_2 = (sll_node*)malloc( sizeof(sll_node) );
    sll_node* node_3 = (sll_node*)malloc( sizeof(sll_node) );

    // Make their values 10, -20, 15, and 4 and link them in that order
    node_0->data = 10;
    node_1->data = -20;
    node_2->data = 15;
    node_3->data = 4;

    // Point to the next one in this order, and set the last to NULL
    node_0->next_node = node_1;
    node_1->next_node = node_2;
    node_2->next_node = node_3;
    node_3->next_node = NULL;

    // Free four sll_nodes with dynamic memory allocation
    free( node_0 );
    free( node_1 );
    free( node_2 );
    free( node_3 );

    return EXIT_SUCCESS;

}
