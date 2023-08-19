#include <stdio.h>

int main( void ){

	int x = 22;
	int y = 23;

	fprintf( stdout, "%d %x %p\n", x, x, &x );
	fprintf( stdout, "%d %x %p\n", y, y, &y );

	if( x == y  ){
		fprintf( stdout, "The values are equal\n" );
		x++;
	}
	else if( y - x == 1 ){
		fprintf( stdout, "y is one greater than x\n" );
	}
	else
		fprintf( stdout, "Neither of our conditions were met.\n" );

	return 0;
}
