#include "palindrome.h"



int main(const int argc, const char* argv[]) {

    // check if valid
    if (argc != 3) {
        COUT << "Need argument, input file, and output file." << ENDL;
    }

    // initialize ifstream & check a valid open
    std::ifstream input_stream(argv[1]);
    if ( !input_stream ) {
        COUT << argv[1] << " is an invalid test file." << ENDL; 
        return EXIT_FAILURE;
    }
    
    // initialize ofstream & check if output file is valid
    std::ofstream output_stream( argv[2] );

    // iterate through and read the string & check if a palindrome permutation
    std::string input_string;
    while ( input_stream >> input_string ) {

        if ( is_palindrome( input_string ) ) {
            output_stream << input_string << " is a palindrome permutation" << ENDL;
        }
        else {
            output_stream << input_string << " is not a palindrome permutation" << ENDL;
        }

    }

    input_stream.close(); // close the ifstream
    output_stream.close(); // close the ofstream
    
    return 0;

}
