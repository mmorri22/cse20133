#include <stdio.h>

int main(void){

	unsigned int the_int = -56;

	fprintf( stdout, "int the_int = %u %x %p\n", the_int, the_int, &the_int );
	return 0;

}
