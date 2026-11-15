#include <stdio.h>
#include <stdlib.h>

/* Two macros that look like functions, but are text substitution */
#define SQUARE(x) x * x
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* The same two operations as real functions */
static inline int square(int x)
{
	return x * x;
}

static inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main(void)
{
	int offset = 3;
	fprintf(stdout, "SQUARE(offset + 1) = %d\n", SQUARE(offset + 1));
	fprintf(stdout, "square(offset + 1) = %d\n\n", square(offset + 1));

	int retries = 5;
	int result = MAX(retries++, 2);
	fprintf(stdout, "MAX(retries++, 2) = %d, retries is now %d\n", result, retries);

	retries = 5;
	result = max(retries++, 2);
	fprintf(stdout, "max(retries++, 2) = %d, retries is now %d\n", result, retries);

	return EXIT_SUCCESS;
}
