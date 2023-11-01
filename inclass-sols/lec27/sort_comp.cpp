/**********************************************
* File: sort_comp.cpp
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* Compares the speed of counting sort and insertion sort
**********************************************/
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <ctime>

void update_hash( std::unordered_map< int, int >& count_sort, const std::vector<int>& the_vals ){

	for( long unsigned int iter = 0; iter < the_vals.size(); ++iter ){

		/* Read from the array to prevent multiple reads - Speeds up the process */
		int curr_val = the_vals.at(iter);

		/* If it doesn't contain the value */
		if( !count_sort.contains( curr_val ) ){
			count_sort.insert( { curr_val, 1} );
		}
		else{
			/* Otherwise, incement the result */
			count_sort.at( curr_val )++;
		}
	}
}


 void insertion_sort( std::vector<int>& sort_array)
 {
   /*Create a variable to count how much of the array is sorted*/
   long unsigned int sortIndex = 1;
   /*Create a variable to hold the number I am trying to sort*/
   int currentNum;
   /*Create a variable to hold the value I am comparing the current value to*/
   int compareNum;

   while (sortIndex < sort_array.size()){

     /*Set currentNum equal to the value starting the unsorted array*/
     currentNum = sort_array.at(sortIndex);

     for (long unsigned int indexCounter = sortIndex; indexCounter > 0; indexCounter--){
       compareNum = sort_array.at(indexCounter-1);

       /*If the value we are looking at is less than the value directly
       to its left, switch the two values*/
       if (currentNum < compareNum)
       {
         sort_array.at(indexCounter) = compareNum;
         sort_array.at(indexCounter-1) = currentNum;
       }
     }

     sortIndex++;
   }
 }

/********************************************
* Function Name  : main
* Pre-conditions :
* Post-conditions: int
*
* Main driver function. Solution  
********************************************/
int main( const int argc, const char* argv[] ){

	if( argc != 2 ){
		std::cerr << "Incorrect Number of Inputs" << std::endl;
		return EXIT_FAILURE;
	}

	/* Run 10,000,000 tests */
	long unsigned int num_values = (long unsigned int)atoi( argv[1] );

	/* See the random number generator */
	srand ( (unsigned int)time(0));

	/* The Hash Table for the Counting Sort */
	std::unordered_map<int, int> count_sort;
	
	/* A singly-linked list of values to sort */
	std::vector<int> the_vals;

	for(long unsigned int iter = 0; iter < num_values; ++iter){
		the_vals.push_back( rand() % 500 );
	}

	/*************************************************
	 * Start Counting Sorting Algorithm
	 ************************************************/
	clock_t hash_time_start = clock();

	/* Get the largest number, which is the number of buckets */
	int largestNum = 0;

	/* Learn about a new */
	for(long unsigned int iter = 0; iter < the_vals.size(); ++iter ){
		
		if(the_vals.at(iter) > largestNum){
			largestNum = the_vals.at(iter);
		}
		
	}
	
	update_hash( count_sort, the_vals );


	/* Obtain the end time and complete the time profile */
	clock_t hash_time_end = clock();

	/*************************************************
	 * Stop Counting Sorting Algorithm
	 ************************************************/

	/* compute average execution time */
	double hash_avg_clks = ((double)hash_time_end - (double)hash_time_start) / (double)CLOCKS_PER_SEC;

	std::cout << "Hash Sort Time: " << hash_avg_clks << " seconds" << std::endl;

	/*************************************************
	 * Start Insert Sort Algorithm
	 ************************************************/
	clock_t insert_time_start = clock();

	insertion_sort( the_vals );

	/* Obtain the end time and complete the time profile */
	clock_t insert_time_end = clock();

	/*************************************************
	 * Stop Insert Sort Algorithm
	 ************************************************/

	/* compute average execution time */
	double insert_avg_clks = ((double)insert_time_end - (double)insert_time_start) / (double)CLOCKS_PER_SEC;

	std::cout << "Insert Sort Time: " << insert_avg_clks << " seconds" << std::endl;

	return 0;
}
