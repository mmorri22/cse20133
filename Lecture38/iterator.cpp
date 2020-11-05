/**********************************************
* File: iterator.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains an example of std::forward_list
* and std::vector using STL iterators
**********************************************/

#include<iostream> 
#include<vector>		// Implement Vector
#include<forward_list>  // Implement Singly Linked List

template<class T>
void printValues(std::forward_list<T>& theList){
	std::cout << "The elements are : "; 
	
    for (T& a : theList) 
        std::cout << a << " "; 
	
    std::cout << std::endl; 
}


template<class T>
void printValues(std::vector<T>& theList){
	std::cout << "The elements are : "; 
	
    for (T& a : theList) 
        std::cout << a << " "; 
	
    std::cout << std::endl; 
}

int main(){
	
    // Declaring forward list int and the iterators
    std::forward_list<int> flistInt = {1,2,7,3,4};
	printValues(flistInt);

	for(auto fwdPtr = flistInt.begin(); *fwdPtr != 3; ++fwdPtr){
		if(*fwdPtr == 7){
			*fwdPtr = 1842;
		}
	}
	
	for(int& intVal : flistInt){
		if(intVal == 3){
			intVal = 77;
		}
	}
	flistInt.push_front(0);
	printValues(flistInt);
	
    // Declaring forward list std::string and the iterators
    std::vector< std::string > vecStr = {"Let's", "Go", "Irish!"};
	printValues(vecStr);
	
	for(std::string& a : vecStr){
		if(a == "Let's"){
			a = "Here We";
		}
	}
	
	vecStr.push_back("Here We Go!");
	printValues(vecStr);
	
	return 0;
}
