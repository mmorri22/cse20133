/**********************************************
* File: nameGood.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of fixing the namespace conflict
* in namespace.cpp
*
* Lecture 02 - Part 2 - Slide 11
**********************************************/
#include <iostream>

namespace foo{
	
	int cout(){
		return 10;
	}
	
}


int main(){
	
	std::cout << foo::cout() << std::endl;
	
	return 0;
	
}
