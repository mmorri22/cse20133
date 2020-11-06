/**********************************************
* File: namespace.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* An example of when using namespace can be bad 
*
**********************************************/
#include <iostream>

namespace foo{
	
	int cout(){
		return 10;
	}
	
}

using namespace std;
using namespace foo;

int main(){
	
	cout << cout() << endl;
	
	return 0;
	
}
