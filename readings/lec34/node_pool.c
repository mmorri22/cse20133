#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 8

typedef struct node {
	int data;
	struct node *next_node;
} node_t;

/* All memory the list will ever use, reserved when the program starts */
static node_t pool[POOL_SIZE];

/* Unused nodes are kept on their own linked list: the "free list" */
static node_t *free_list = NULL;

/* Called once at startup: link every pool node onto the free list */
void pool_init(void)
{
	for (int i = 0; i < POOL_SIZE - 1; i++) {
		pool[i].next_node = &pool[i + 1];
	}
	pool[POOL_SIZE - 1].next_node = NULL;
	free_list = &pool[0];
}

/* Replaces malloc: take the first node off the free list, or NULL if empty */
node_t *pool_alloc(void)
{
	if (free_list == NULL) {
		return NULL;
	}
	node_t *node = free_list;
	free_list = free_list->next_node;
	node->next_node = NULL;
	return node;
}

/* Replaces free: put the node back at the front of the free list */
void pool_release(node_t *node)
{
	if (node != NULL) {
		node->next_node = free_list;
		free_list = node;
	}
}

int main(void)
{
	pool_init();
	node_t *head = NULL;

	/* Try to insert 10 values into a pool that holds 8 */
	for (int i = 0; i < 10; i++) {
		node_t *node = pool_alloc();
		if (node == NULL) {
			fprintf(stdout, "Insert %d rejected: pool of %d nodes is full\n", i, POOL_SIZE);
			continue;
		}
		node->data = i;
		node->next_node = head;
		head = node;
		fprintf(stdout, "Inserted %d at address %p\n", i, (void *)node);
	}

	/* Remove the first node and show that its memory is reused */
	node_t *removed = head;
	head = head->next_node;
	fprintf(stdout, "Removed %d from address %p\n", removed->data, (void *)removed);
	pool_release(removed);

	node_t *reused = pool_alloc();
	fprintf(stdout, "Next allocation returned address %p\n", (void *)reused);

	return EXIT_SUCCESS;
}
