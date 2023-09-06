#include <stdio.h>

void print_while( unsigned int total_points_pw, 
	unsigned int point_for_a_pw );

int main( void ){

	/* Create Variable */
	unsigned int total_points = 0;
	unsigned int point_for_a = 93;	

	print_while( total_points, point_for_a );

	return 0;
}

void print_while( unsigned int total_points_pw, 
	unsigned int point_for_a_pw ){

	/* While Loop Statement */
	while( total_points_pw < point_for_a_pw ){

		total_points_pw += 7;

		fprintf( stdout, "%u %p %u %p\n", total_points_pw, 
			&total_points_pw, point_for_a_pw, &point_for_a_pw);
	}

}
