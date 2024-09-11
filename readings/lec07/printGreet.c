#include <stdio.h>

/* Function Declarations */
void printGreeting( int year );


/* Main Function */
int main( void ){
	
	int yearSophs = 2022;
	int yearJuniors = 2021;
	int yearSeniors = 2020;

	printGreeting( yearSophs );
	printGreeting( yearJuniors );
	printGreeting( yearSeniors );
	
	return 0;
}

/* Function Definitions */
void printGreeting( int year ){
	
	fprintf( stdout, "Hello Notre Dame Students!\n" );
	fprintf( stdout, "You are graduating in %d\n", year );
	
}


