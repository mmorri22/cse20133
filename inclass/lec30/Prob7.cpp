#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> func( std::vector<int>& the_vec ){

    std::unordered_map<int, int> the_map;
    std::vector<int> return_vec;
    
    int val = 0;
    
    for( long unsigned int iter = 0; iter < the_vec.size(); ++iter ){
    
        // When working on this problem, we will brifely discuss this: "teritary operator"
        // What this means: if the_vec.at(iter) > val, then val = the_vec.at(iter). else val = val
        val = ( the_vec.at(iter) > val ) ? the_vec.at(iter) : val;
        
        if( the_map.count( the_vec.at(iter) ) > 0 ){
            the_map.at( the_vec.at(iter) )++;
        }
        else{
            the_map.insert( {the_vec.at(iter), 1} );
        }
    }
    
    for( int iter = 0; iter <= val; ++iter ){
    
        for( int jter = 0; jter < the_map[iter]; ++jter ){
            return_vec.push_back( iter );
        }
    }
    
    return return_vec;
}

void print_vec( const std::vector<int>& the_vec ){

    for( long unsigned int iter = 0; iter < the_vec.size(); ++iter ){
        std::cout << the_vec.at(iter) << " ";
    }
    
    std::cout << std::endl;
}

int main()
{
    std::vector<int> the_vec = { 22, 17, 13, 8, 2, 22, 8, 14, 17, 2, 17, 1 };
    print_vec( func( the_vec ) );
    
    return 0;
}