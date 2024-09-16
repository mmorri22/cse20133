#include <stdio.h>

int main( void ){

	long unsigned int lui_loop_var = 10;

	while( lui_loop_var >= 0 ){

		fprintf( stdout, "lui_loop_var at %p = %ld %lx\n",
			&lui_loop_var, lui_loop_var, lui_loop_var );

		--lui_loop_var;

	}

	return 0;

}
