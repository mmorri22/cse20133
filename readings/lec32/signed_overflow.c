#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Is x + 1 smaller than x? Mathematically, only if x + 1 "wrapped around". */
int wraps(int x)
{
	return x + 1 < x;
}

int main(void)
{
	int x = INT_MAX;
	fprintf(stdout, "x = %d, wraps(x) = %d\n", x, wraps(x));
	return 0;
}
