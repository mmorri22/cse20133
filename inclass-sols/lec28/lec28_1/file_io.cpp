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
    std::ifstream input_stream( argv[1] );

    if( !input_stream ){
        std::cerr << "Invalid Stream" << std::endl;
        return EXIT_FAILURE;
    }

    long unsigned int num_inputs;
    if( input_stream >> num_inputs ){}

    // Memory Allocate
    inputs* the_inputs = (inputs*)malloc( num_inputs*sizeof(inputs) );

    long unsigned int iter = 0;
    while( iter < num_inputs ){

        /* Read in here */
        if( input_stream >> the_inputs[iter].the_int >> the_inputs[iter].the_float
            >> the_inputs[iter].the_double ){}

        ++iter;
    }

    // Close the input stream
    input_stream.close();

     /* Output Stream */
    std::ofstream output_stream( argv[2] );

    output_stream << num_inputs << std::endl;

    iter = 0;
    while( iter < num_inputs ){

        output_stream << the_inputs[iter].the_int << " ";
        output_stream << the_inputs[iter].the_float << " ";
        output_stream << the_inputs[iter].the_double << std::endl;
        ++iter;
    }

    /* Close the output stream */
    output_stream.close();

    // Free the memory
    free( the_inputs );

    return EXIT_SUCCESS;
}