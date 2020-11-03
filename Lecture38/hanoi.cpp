/*******************************
 * File name: Section01_hanoi.cc  
 * Author: Matthew Morrison
 * E-mail: matt.morrison@nd.edu 
 * 
 * This file contains the main classes
 * for the Towers of Hanoi problem.
 * ****************************/

#include <iostream>
#include <stack>
#include "Tower.h"

/*********************************************
 * Function Name: hanoi
 * Preconditions: Tower*, Tower*, Tower* size_t
 * Postconditions: none 
 * This function pops the top element off the 
 * source stack, puts in on the top of the 
 * destination stack, and prints the move to 
 * the user 
 * ******************************************/ 
void move(Tower& source, Tower& destination, int& numMoves){
	
    numMoves++;
	
    std::cout   << "Move " << numMoves << ": Weight #" << source.theStack.top() << " from "
                << source.getTowerNum() << " to " 
                << destination.getTowerNum() << std::endl;
                
	destination.theStack.push(source.theStack.top());
	 
	source.theStack.pop();
}


/*********************************************
 * Function Name: hanoi
 * Preconditions: unsigned int n, Tower& source, Tower& destination, Tower& auxillary, unsigned int& numMoves
 * Postconditions: none 
 * This function contains the Towers of Hanoi algorithm 
 * ******************************************/ 
void hanoi(int n, Tower& source, Tower& destination, 
	Tower& auxillary, int& numMoves){
    if (n > 0 ){
        hanoi(n - 1, source, auxillary, destination, numMoves);   
        move(source, destination, numMoves);               
        hanoi(n - 1, auxillary, destination, source, numMoves);     
    }

}

/*********************************************
 * Function Name: main
 * Preconditions: int, argc**
 * Postconditions: none 
 * This function is the main driver function 
 * ******************************************/ 
int main(int argc, char**argv){
	
	if(argc != 2){
		std::cout << "Incorrect number of inputs\n" << std::endl;
	}
    
    // Total Number of Plates
    int STACK_SIZE = atoi(argv[1]);
    
    // Keep track of the number of moves 
    int numMoves = 0;
    
    // Create three stacks for the three rods
	Tower tower1(1);
	Tower tower2(2);
	Tower tower3(3);
    
    // Put the initial plates on the first tower
    for(int i = STACK_SIZE; i > 0; --i){
        tower1.theStack.push(i);
    }
    
    // Run the Hanoi algorithm
    hanoi(STACK_SIZE, tower1, tower2, tower3, numMoves);
    
    return 0;
}