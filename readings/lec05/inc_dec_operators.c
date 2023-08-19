#include <stdio.h>

int main(void){

	int x = 5;

	fprintf( stdout, "Initial x is %d\n", x );

	fprintf( stdout, "After ++x, the value is %d\n", ++x);

	fprintf( stdout, "After x++, the value is %d\n", x++);

	fprintf( stdout, "The current value of x is now %d\n", x);

	fprintf( stdout, "After --x, the value is %d\n", --x);

	fprintf( stdout, "After x--, the value is %d\n", x--);

	fprintf( stdout, "The current value of x is not %d\n", x);

	return 0;
}
