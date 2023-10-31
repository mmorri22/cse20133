/**********************************************
* File: countSort.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Shows a basic example of Counting Sort
* using the C++ STL Libraries
**********************************************/
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

void update_hash( std::unordered_map< int, int >& count_sort, const std::vector<int>& the_vals ){

	for( long unsigned int iter = 0; iter < the_vals.size(); ++iter ){

		/* If it doesn't contain the value */
		if( !count_sort.contains( the_vals.at(iter) ) ){
			count_sort.insert( {the_vals.at(iter), 1} );
		}
		else{
			/* Otherwise, incement the result */
			count_sort.at(the_vals.at(iter))++;
		}
	}
}

void print_hash(std::unordered_map< int, int >& countSort, int largestNum){

	for(int i = 0; i <= largestNum; i++){
		
		if( countSort.contains(i) ){
			for(int j = 0; j < countSort.at(i); ++j){
				
				std::cout << i << " ";
			}
		}
	}
	
	std::cout << std::endl;
	
}

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main( ){

	/* The Hash Table for the Counting Sort */
	std::unordered_map<int, int> count_sort;
	
	/* A singly-linked list of values to sort */
	std::vector<int> the_vals{7, 1, 5, 7, 1, 4, 100};
	
	/* Get the largest number, which is the number of buckets */
	int largestNum = 0;

	/* Learn about a new */
	for(long unsigned int iter = 0; iter < the_vals.size(); ++iter ){
		
		if(the_vals.at(iter) > largestNum){
			largestNum = the_vals.at(iter);
		}
		
	}
	
	update_hash( count_sort, the_vals );

	/* Print the Hash */
	print_hash(count_sort, largestNum);

	return 0;
}
