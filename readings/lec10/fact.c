#include <stdio.h>
#include <stdlib.h>

int factorial( int fact_num ){

	if( fact_num == 1 )
		return 1;

	return fact_num * factorial( fact_num - 1 );

}

int main( void ){

	int fact_num = 5;

	fprintf( stdout, "%d! = %d\n", fact_num, factorial( fact_num ) );

	return EXIT_SUCCESS;

}
