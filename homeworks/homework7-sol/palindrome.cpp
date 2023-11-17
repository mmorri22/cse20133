#include "palindrome.h"


int is_palindrome( const std::string& str ){

    std::unordered_map<char, int> tracker; // empty tracker

    int num_odd = 0;

    for (long unsigned int iter = 0; iter < str.length(); iter++ ) { // iterate through each char
        
        // if character in set, delete it
        if ( !tracker.contains(str.at(iter)) ) {

            tracker.insert( {str.at(iter), 1} );
            num_odd++;

        }
        else { 
            
            // Update the count
            tracker.at(str.at(iter))++;

            if( tracker.at(str.at(iter)) % 2 == 0  ){
                num_odd--;
            }
            else{
                num_odd++;
            }
        }
    }
    
    // if num_odd has a size of 0 or 1, then the str is a palindrome permutation. Otherwise it isn't
    return num_odd < 2 ? 1 : 0;

}
