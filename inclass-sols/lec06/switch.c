#include <stdio.h>

int main( void ){

	/* Create variables for comparison */
	unsigned int discussion_group = 3;

	/* If-Else If Build */
	switch(discussion_group){
		case 1:
			fprintf(stdout, "Group 1 develops an if-else\n");
			break;

		case 2:
			fprintf(stdout, "Group 2 develops a switch\n");
			break;

		case 3:
			fprintf(stdout, "Group 3 develops a while loop\n");
			break;

		default:
			fprintf(stdout, "Ask your prof for a discussion group\n");
			break;
	}

	return 0;

}
