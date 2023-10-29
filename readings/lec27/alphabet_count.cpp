#include <iostream>
#include <string>
#include <unordered_map>

#define SIZE_T long unsigned int

// Pass by reference so we don't make a copy of the string, just an abstractd pointer
std::unordered_map< char, int > find_count( const std::string& the_string ){

    // Create the Hash
    std::unordered_map< char, int > alphabet_hash;

    // Iterate through the entire string
    for( SIZE_T iter = 0; iter < the_string.size(); ++iter ){

        // If the character is *not* a key in the hash
        if( !alphabet_hash.contains( the_string.at( iter ) ) ){

            // Insert the key in the location in the Hash
            alphabet_hash.insert( { the_string.at( iter ) , 1} );

        }
        else{

            // Increment the value at the specified key
            alphabet_hash.at( the_string.at( iter ) )++;

        }
    }

    return alphabet_hash;

}

void print_results( const std::string& the_string, const std::unordered_map< char, int >& alphabet_hash  ){

    char the_char = 'a';

    std::cout << "Counts for " << the_string << ": ";

    while( the_char <= 'z' ){

        if( alphabet_hash.contains( the_char ) ){
            std::cout << "{" << the_char << ", " << alphabet_hash.at(the_char) << "} ";
        }
        ++the_char;
    }
    std::cout << std::endl;
}

int main()
{
    std::string test_0 = "a";
    std::unordered_map< char, int > the_hash = find_count( test_0 );

    std::cout << "Test 2" << std::endl;
    print_results( test_0, the_hash );

    // Clear the Hash
    the_hash.clear();

    std::string test_1 = "the quick brown fox jumps over the lazy dog";

    std::cout << "Test 1" << std::endl;
    the_hash = find_count( test_1 );
    print_results( test_1, the_hash );

    return 0;
}