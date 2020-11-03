#include <iostream>
#include <cstdlib>
#include <cmath>

#define COUT std::cout
#define ENDL std::endl

std::pair<bool, std::pair<double, double> > quadratic( double a, double b, double c ){
	
	double insideSqrt = b*b - 4*a*c;
	
	double demonimator = 2*a;
	
	std::pair<bool, std::pair<double, double> > solutions;
	
	if( insideSqrt < 0 || demonimator == 0 ){
		
		solutions.first = false;
	}
	else{
	
		solutions.first = true;
		solutions.second.first = ( -b + sqrt(insideSqrt) ) / ( 2 * a );
		solutions.second.second = ( -b - sqrt(insideSqrt) ) / ( 2 * a );
	
	}
	
	return solutions;
}

void printSolution( std::pair<bool, std::pair<double, double> >& solution ){
	
	if( solution.first ){
		COUT << "{" << solution.second.first << ", " << solution.second.second << "}\n";
	}
	else{
		COUT << "Invalid result." << ENDL;
	}
	
}

int main() {
	
	std::pair<bool, std::pair<double, double> > solution = quadratic( 2, 4.1, -3.7 );
	
	printSolution( solution );
	
	std::pair<bool, std::pair<double, double> > solution2 = quadratic( 2, 4.1, 3.7 );
	
	printSolution( solution2 );
	
	return 0;
}