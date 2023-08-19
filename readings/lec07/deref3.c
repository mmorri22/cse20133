#include <stdio.h>

int main(){

	int x = 10;
	int y = 25;
	int* int_ptr = &x;

	fprintf( stdout, "x = %d, y = %d\n", x, y );

  /* Copy x into a swap variable */
	int swap = *int_ptr;

	/* Change int_ptr to point at y */
	int_ptr = &y;

	/* Set x to y's value using int_ptr */
	x = *int_ptr;

	/* Set y to swap value using the pointer */
	*int_ptr = swap;

	fprintf( stdout, "x = %d, y = %d\n", x, y );

	return 0;
}
