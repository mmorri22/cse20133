#include <iostream>
#include <cstdlib>

int main( const int argc, const char* argv[] ){

    if( argc != 2 )
        return EXIT_FAILURE;

    int iter_max = atoi( argv[1] );
    while (iter_max > 0){
        
        std::cout << iter_max << " ";
        
        iter_max /= 2;
    }
    std::cout << std::endl;

    return 0;
}
