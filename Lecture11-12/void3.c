/**********************************************
* File: void3.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This is a basic program to show students how to 
* allocate a void point and memory, set the first two
* bytes equal to characters, and then print their 
*
* Lecture 02 - Slides 30-32
**********************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	long unsigned int numCharacters = 13;
	
	void* hello = malloc( numCharacters * sizeof(char) );
	void* reference = hello;
	
	*((char *)(reference)) = 72;
	reference = (char *)reference + sizeof(char);
	*((char *)(reference)) = 101;
	
	fprintf( stdout, "%p %c\n", (void *)hello, *((char *)hello + 1));
	fprintf( stdout, "%p %c\n", (void *)reference, *((char *)reference - 1));
	
	free( hello );

	return 0;
}
