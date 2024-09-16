#include <stdio.h>

int main( void ){

	/* Create Variable */
	int needed_wins;

	/* For Loop Statement */
	for(needed_wins = 0; needed_wins <= 11; ++needed_wins){

		fprintf( stdout, "ND needs %u wins to make the playoff!\n", 11-needed_wins);

	}

	return 0;
}
