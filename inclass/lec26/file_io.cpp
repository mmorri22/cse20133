#include <iostream>
#include <fstream>

typedef struct inputs{

    int the_int;
    float the_float;
    double the_double;

}inputs;

int main(const int argc, const char* argv[] ){

    // Protect the inputs
    if( argc != 3 ){
        fprintf( stdout, "Incorrect Number of Inputs\n" );
        return EXIT_FAILURE;
    }

    /* Input Stream */
    



    long unsigned int num_inputs;
    if( /* Replace Comment */ ){}

    // Memory Allocate
    inputs* the_inputs = (inputs*)malloc( num_inputs*sizeof(inputs) );

    long unsigned int iter = 0;
    while( iter < num_inputs ){

        /* Read in here */

        ++iter;
    }

    // Close the input stream
    

     /* Output Stream */
    

    

    iter = 0;
    while( iter < num_inputs ){

        

        ++iter;
    }

    /* Close the output stream */
    

    // Free the memory
    free( the_inputs );

    return EXIT_SUCCESS;
}