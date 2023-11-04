#include <iostream>
#include <vector>
#include <unordered_map>

void two_sums( const std::vector<int>& the_vec, int sum_result ){

	std::unordered_map<int, int> the_map;

	for(long unsigned int iter = 0; iter < the_vec.size(); ++iter ){

		int val1 = the_vec.at(iter);

		if( !the_map.contains( val1 ) ){

			the_map.insert( { val1, iter } );
		}
		
		int val2 = sum_result - val1;

		if( the_map.contains( val2 ) ){

			// Uncomment print statements when we have the logic
			std::cout << "{" << val1 << "," << iter << "} and ";
			std::cout << "{" << val2 << "," << the_map.at(val2) << "} ";
			std::cout << " sum to " << sum_result;
			std::cout << std::endl;
			return;
		}

	}

	std::cout << "No pair sums to " << sum_result << std::endl;

}

int main(){
	
	std::cout << "Test 1:" << std::endl;
	std::vector<int> test1 = { 2, 7, 11, 15 };
	two_sums( test1, 26 );
	two_sums( test1, 18 );
	two_sums( test1, 10 );

	std::cout << std::endl << "Test 2:" << std::endl;	
	std::vector<int> test2 = { 44, 18, 99, 102, 55, 1, 7, 88, 206, 77, 67 };
	two_sums( test2, 143 );
	two_sums( test2, 144 );
	two_sums( test2, 8 );
	two_sums( test2, 56 );
	two_sums( test2, 308 );
	two_sums( test2, 100 );
	two_sums( test2, 101 );
	
	return 0;
}

