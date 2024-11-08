/**********************************************
* File: namespace_fixed.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of fixing the namespace conflict
* in namespace.cpp
**********************************************/
#include <iostream>

#define COUT std::cout
#define ENDL std::endl

namespace foo{
	
	int cout(){
		return 10;
	}
}

int main(){
	
	COUT << foo::cout() << ENDL;
	
	return 0;
	
}
