#include <stdio.h>

int main(void){

	int the_int = -56;

	fprintf( stdout, "int the_int = %d %x %p\n", the_int, the_int, &the_int );
	return 0;

}
