#include <stdio.h>
#include <stdlib.h>

typedef struct sll_node {
	int data;
	struct sll_node *next_node;
} sll_node;

/* The recursive destructor from Lecture 24 and Homework 8 */
void destructor_recursive(sll_node *curr_ptr)
{
	if (curr_ptr != NULL) {
		destructor_recursive(curr_ptr->next_node);
		free(curr_ptr);
	}
}

/* The same job as a loop: walk the list, freeing as we go */
void destructor_iterative(sll_node *curr_ptr)
{
	while (curr_ptr != NULL) {
		sll_node *next = curr_ptr->next_node;
		free(curr_ptr);
		curr_ptr = next;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <num_nodes> <recursive|iterative>\n", argv[0]);
		return EXIT_FAILURE;
	}

	long num_nodes = strtol(argv[1], NULL, 10);
	sll_node *head = NULL;

	for (long i = 0; i < num_nodes; i++) {
		sll_node *node = (sll_node *)malloc(sizeof(sll_node));
		if (node == NULL) {
			fprintf(stderr, "Allocation failed at node %ld\n", i);
			destructor_iterative(head);
			return EXIT_FAILURE;
		}
		node->data = (int)i;
		node->next_node = head;
		head = node;
	}
	fprintf(stdout, "Built a list of %ld nodes\n", num_nodes);

	if (argv[2][0] == 'r') {
		destructor_recursive(head);
	}
	else {
		destructor_iterative(head);
	}
	fprintf(stdout, "Deleted the list with the %s destructor\n", argv[2]);
	return EXIT_SUCCESS;
}
