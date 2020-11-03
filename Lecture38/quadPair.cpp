#include <iostream>
#include <cstdlib>
#include <cmath>

#define COUT std::cout
#define ENDL std::endl

std::pair<double, double> quadratic( double a, double b, double c ){
	
	double insideSqrt = b*b - 4*a*c;
	
	std::pair<double, double> solutions;
	
	solutions.first = ( -b + sqrt(insideSqrt) ) / ( 2 * a );
	
	solutions.second = ( -b - sqrt(insideSqrt) ) / ( 2 * a );
	
	return solutions;
}

void printSolution( std::pair<double, double>& solution ){
	
	COUT << "{" << solution.first << ", " << solution.second << "}\n";
	
}

int main() {
	
	std::pair<double, double> solution = quadratic( 2, 4.1, -3.7 );
	
	printSolution( solution );
	
	std::pair<double, double> solution2 = quadratic( 2, 4.1, 3.7 );
	
	printSolution( solution2 );
	
	return 0;
}