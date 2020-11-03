/**********************************************
* File: ageHash.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of STL C++ Hash Map
**********************************************/
#include <unordered_map>
#include <string>
#include <iostream>

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main(){
	
	std::unordered_map<std::string, int> ageHash = { {"Matthew", 38}, {"Alfred", 72}, {"Grace", 14}, {"James", 35} };
	
	/* Get the age of the each */
	std::cout << "James' Age Is: " << ageHash["James"] << std::endl;
	std::cout << "Matthew's Age Is: " << ageHash["Matthew"] << std::endl;
	std::cout << "Alfred's Age Is: " << ageHash["Alfred"] << std::endl;
	std::cout << "Grace's Age Is: " << ageHash["Grace"] << std::endl;
	
	return 0;
}

