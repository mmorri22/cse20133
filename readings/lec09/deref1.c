#include <stdio.h>

int main(){

	int x = 10;
	int* int_ptr = &x;

  /* Basic register information for x */
	fprintf( stdout, "x = %d, located at %p\n", x, &x);

  /* All the reference and de-referencing */
  /* Notice the last output specifier (%d) maps to *int_ptr */
	fprintf( stdout, "&int_ptr = %p, int_ptr: %p, *int_ptr = %d\n\n",
			&int_ptr, int_ptr, *int_ptr );

	return 0;
}
