i#include <stdio.h>

int main( void ){

	int the_int;

        for( the_int = 0; the_int <= 10; ++the_int ){
            fprintf( stdout, "the_int at %p = %d %x\n", &the_int, the_int, the_int );
        }

        fprintf( stdout, "the_int = %d\n", the_int );

	return 0;
}
