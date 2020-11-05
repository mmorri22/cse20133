#include "LIS.h"

int main(){
	
	std::vector< int > test1 {10, 9, 2, 5, 3, 7, 101, 18} ;
	
	std::vector< unsigned int > test2 {10, 5, 8, 3, 9, 4, 12, 11} ;
	
	std::vector< unsigned int > test3 {10, 5, 8, 3, 9, 4, 12, 11, 12} ;
	
	std::vector< char > test4 {'e', 'A', 'B', 'a', 'C', 'f', 'D', 'E'} ; 
	
	std::cout << "Test 1 has an LIS of: " << getLIS( test1 ) << std::endl;
	
	std::cout << "Test 2 has an LIS of: " << getLIS( test2 ) << std::endl;
	
	std::cout << "Test 3 has an LIS of: " << getLIS( test3 ) << std::endl;

	std::cout << "Test 4 has an LIS of: " << getLIS( test4 ) << std::endl;
	
	return 0;
}