#include <stdio.h>

int main( void ){

	/* Create variables for comparison */
	unsigned int student_points = 92;

	/* If-Else If Build */
	if( student_points >= 93){
		fprintf(stdout, "Student earned an A\n");
	}
	else if( student_points >= 90 ){
		fprintf(stdout, "Student earned an A-\n");
	}
	else if( student_points >= 87 ){
		fprintf(stdout, "Student earned an B+\n");
	}
	else{
		fprintf( stdout, "Student got a B\n");
	}


	return 0;

}
