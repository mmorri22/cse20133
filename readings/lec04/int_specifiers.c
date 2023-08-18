#include <stdio.h>

int main(void){

	int the_int = -6;
	unsigned int the_uint = 23;

	fprintf( stdout, "%u %x %p\n", the_uint, the_uint, &the_uint );

	fprintf( stdout, "%d %x %p\n", the_int, the_int, &the_int );

	return 0;

}
