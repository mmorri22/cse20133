/**********************************************
* File: helloArray.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of "Hello, World" with procedural
* programming, char array, and pointer arithmetic
*
* Lecture 02 - Slide 41
**********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	long unsigned int numCharacters = 13;
	
	char hello[numCharacters];
	
	hello[0] = 'H';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 'o';
	hello[5] = ',';
	hello[6] = ' ';
	hello[7] = 'W';
	hello[8] = 'o';
	hello[9] = 'r';
	hello[10] = 'l';
	hello[11] = 'd';
	hello[12] = '\n';
	
	for(long unsigned int iter = 0; iter < numCharacters; iter++){
		
		fprintf( stdout, "%c", hello[iter] );
		
	}

	return 0;
}
