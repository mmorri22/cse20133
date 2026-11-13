#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 8

/* Fill the first count + 1 entries of the buffer with zeros. */
void zero_buffer(int buf[], int count)
{
	for (int i = 0; i <= count; i++) {
		buf[i] = 0;
	}
}

int main(int argc, char *argv[])
{
	int buf[BUF_SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int guard = 42;		/* sits near buf on the stack */

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <count>\n", argv[0]);
		exit(-1);
	}

	int count = (int)strtol(argv[1], NULL, 10);
	zero_buffer(buf, count);

	fprintf(stdout, "buf[0] = %d, guard = %d\n", buf[0], guard);
	return 0;
}
