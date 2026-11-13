#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 64

#define OK 0
#define ERR_PARAM 1
#define ERR_NOT_FOUND 2
#define ERR_BOUND 3

typedef struct node {
	int key;
	struct node *next;
} node_t;

/* Rule 3: every node comes from a fixed array, allocated once */
static node_t pool[MAX_NODES];

/* Violates Rules 2 and 7: no bound, and no check for NULL */
node_t *find_unbounded(node_t *n, int key)
{
	while (n->key != key) {
		n = n->next;
	}
	return n;
}

/* Complies with Rules 2 and 7: fixed bound, checked parameters, error codes */
int find_bounded(const node_t *n, int key, const node_t **out)
{
	if (out == NULL) {
		return ERR_PARAM;
	}
	for (int i = 0; i < MAX_NODES; i++) {
		if (n == NULL) {
			return ERR_NOT_FOUND;
		}
		if (n->key == key) {
			*out = n;
			return OK;
		}
		n = n->next;
	}
	return ERR_BOUND;	/* more steps than nodes exist: the list is corrupted */
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <key> <bounded|unbounded>\n", argv[0]);
		return EXIT_FAILURE;
	}
	int key = (int)strtol(argv[1], NULL, 10);

	/* Build a list of 10 nodes with keys 0, 10, 20, ..., 90 */
	for (int i = 0; i < 10; i++) {
		pool[i].key = i * 10;
		pool[i].next = (i < 9) ? &pool[i + 1] : NULL;
	}

	/* Simulate a single corrupted pointer, such as a radiation bit flip:
	 * the last node now points back into the middle of the list */
	pool[9].next = &pool[4];
	fprintf(stdout, "List built. Node 9 now points back to node 4.\n");
	fflush(stdout);

	if (strcmp(argv[2], "unbounded") == 0) {
		node_t *found = find_unbounded(&pool[0], key);
		fprintf(stdout, "Found key %d\n", found->key);
	}
	else {
		const node_t *found = NULL;
		int status = find_bounded(&pool[0], key, &found);
		if (status == OK) {
			fprintf(stdout, "Found key %d\n", found->key);
		}
		else if (status == ERR_BOUND) {
			fprintf(stdout, "ANOMALY: search exceeded %d steps. List is corrupted.\n", MAX_NODES);
		}
		else {
			fprintf(stdout, "Key %d not found\n", key);
		}
	}
	return EXIT_SUCCESS;
}
