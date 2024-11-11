#include <iostream>
#include <cstdlib>
#include <string>

void pass_by_ref( int* print_int, double* print_dbl ){

	std::cout << print_int << " " << print_dbl << std::endl;

	std::cout << &print_int << " " << &print_dbl << std::endl;

	std::cout << *print_int << " " << *print_dbl << std::endl;

}

void call_by_ref( int& print_int, double& print_dbl ){
	
	// In-class code here
	
	
}

int main(){
	
	int print_int = 10;
	double print_dbl = -22.7;
	
	std::cout << "Hello, World" << std::endl;
	
	std::cout << "Addrs in main: " << &print_int << " " << &print_dbl << std::endl;
	
	// Review C++ Example
	pass_by_ref( &print_int, &print_dbl );

	// Initial Call by Reference
	

	// Call again to show changes
	
	
	return EXIT_SUCCESS;
}