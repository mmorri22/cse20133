/*************************************
 * File name: stackTest.cc  
 * Author: Matthew Morrison
 * Email: matt.morrison@nd.edu 
 * 
 * Given a set of inputs from the user, demonstrates
 * min, max, and stack operations 
 * ***********************************/

#include <iostream>
#include <cstdlib>
#include "max_stack.h"

const int INPUT_THROW = 100;

/******************************
 * Function Name: clearSTDCIN
 * Preconditions: none 
 * Postconditions: none
 * 
 * Clears the std::cin buffer in the event 
 * that the user wishes to after an error.
 * ****************************/
void clearSTDCIN(){
	std::cin.clear();
    std::cin.ignore(256, '\n');
}

/******************************
 * Function Name: getInputs
 * Preconditions: none 
 * Postconditions: none
 * 
 * Clears the std::cin buffer in the event 
 * that the user wishes to after an error.
 * ****************************/
void getInputs(unsigned int& stack_size, unsigned int& val_max){

    std::cout << "Enter the values as [size] [range]: ";

    if(!(std::cin >> stack_size)){
		std::cerr << "Input " << stack_size << " is incorrect. Must be an integer." << std::endl;
		exit(-1);
	}
    
    if(!(std::cin >> val_max)){
		std::cerr << "Input " << val_max << " is incorrect. Must be an integer." << std::endl;
		exit(-1);
	}
	
 }

int main()
{  

	unsigned int stack_size;
	unsigned int val_max;
	
	getInputs(stack_size, val_max);
	
	srand( (unsigned int)time(NULL) );
	
	max_stack<int> the_stack;
	
	std::cout << "Elements pushed on the stack: ";
	for(unsigned int i = 0; i < stack_size; i++){
		the_stack.push(rand() % val_max);
	}
	std::cout << std::endl;
	
	std::cout   << "size = " << the_stack.data_size 
				<< ", max_size = " << the_stack.max_size
				<< ", min_size = " << the_stack.min_size << std::endl;
	
	std::cout << std::endl << "Top\tMax\tMin\t" << std::endl;
	for(unsigned int i = 0; i < stack_size; i++){
		std::cout << the_stack.top() << '\t';
		std::cout << the_stack.max() << '\t';
		std::cout << the_stack.min() << std::endl;
		the_stack.pop();
	}

    return 0;
}
