#include <stdio.h>

int main( void ){

	/* Create Variable */
	unsigned int total_points = 0;
	unsigned int point_for_a = 93;	


	/* While Loop Statement */
	do{

		total_points += 7;

		fprintf( stdout, "%u %p %u %p\n", total_points, &total_points,
			point_for_a, &point_for_a);
	}while( total_points < point_for_a );


	return 0;
}
