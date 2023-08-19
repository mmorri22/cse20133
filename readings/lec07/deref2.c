#include <stdio.h>

int main(){

	int x = 10;
	int* int_ptr = &x;

  /* Basic register information for x */
	fprintf( stdout, "x = %d, located at %p\n", x, &x);

  /* All the reference and de-referencing */
	fprintf( stdout, "&int_ptr = %p, int_ptr: %p, *int_ptr = %d\n",
			&int_ptr, int_ptr, *int_ptr );

	/* Set y to *int_ptr */
	int y = *int_ptr;

	/* Basic register information for y */
	fprintf( stdout, "y = %d, located at %p\n", y, &y);

	return 0;
}
