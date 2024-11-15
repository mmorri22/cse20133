#include <iostream>
#include <vector>

/* Compiler Directives for std::coutand std::endl */
#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

int main()
{
    
    VECTOR<int> int_vector;

    COUT << "Before Loop: ";
    COUT << &int_vector << " ";
    COUT << int_vector.size() << " ";
    COUT << int_vector.capacity() << ENDL;
    
    for( int iter = 0; iter < 10; ++iter ){
        /* Push back, then print the size and capacity */
        int_vector.push_back(iter*2);

        COUT << int_vector.at(iter) << " "; 
        COUT << &(int_vector.at(iter)) << " "; 
        COUT << int_vector.size() << " ";
        COUT << int_vector.capacity() << ENDL;
    }
    

    // Print the base address of the vector
    COUT << "Before Loop 2: ";
    COUT << &int_vector << ENDL;   
    
    for( int iter = 0; iter < 10; ++iter ){

        // Print the value and address using the .at operator
        COUT << int_vector.at(iter) << " "; 
        COUT << &(int_vector.at(iter)) << " "; 
        COUT << int_vector.size() << " ";
        COUT << int_vector.capacity() << ENDL;       
    }   
	

    return 0;
}