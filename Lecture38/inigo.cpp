/**********************************************
* File: list.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Contains an example of std::list, for 
* a Doubly Linked List
**********************************************/

#include<iostream> 
#include<list>  // Implement Doubly Linked List

template<class T>
void printValues(std::list<T>& theList){
    for (T& a : theList){ 
        std::cout << a << " "; 
	}
    std::cout << std::endl; 
}

const unsigned int SIXFINGEREDMAN = 6;

int main(){
	
    // Declaring forward list int and the iterators
    std::list< std::string > strList{ "is" };	printValues(strList);
	strList.push_front("name");  	printValues(strList);
	strList.push_back("Inigo");  	printValues(strList); 
	strList.push_front("My");		printValues(strList);
	strList.push_back("Montoya!"); 	printValues(strList);

	for(std::string& strVal : strList){
		if(strVal == "Montoya!"){
			strVal = "Montoya! You killed my grandfather!";
		}
	}
	printValues(strList);
	strList.pop_back(); printValues(strList);
	strList.push_back("Montoya! You killed my father! Prepare to die!");
	printValues(strList);
	
	strList.push_front("Bonjour!");
	printValues(strList);
	strList.pop_front(); printValues(strList);
	strList.push_front("Hello!");
	
	std::cout << "Inigo is ready to confront the Six Fingered Man!" << std::endl;
	for(unsigned int i = 0; i < SIXFINGEREDMAN; ++i){
		printValues(strList);
	}
	
	return 0;
}
