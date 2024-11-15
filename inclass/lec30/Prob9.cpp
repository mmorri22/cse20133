#include <iostream>
#include <unordered_map>

int func( std::unordered_map<int, int>& the_map, int val ){

    if( the_map.contains( val ) ){

        std::cout << val << " " << the_map.at(val) << std::endl;

        return the_map.at(val);
    }

    if( val == 0 || val == 1){
        the_map.insert( {val, 1} );

        std::cout << val << " " << the_map.at(val) << std::endl;

        return 1;
    }

    int result = func(the_map, val - 1) + func(the_map, val - 2);
    the_map.insert( {val, result} );

    std::cout << val << " " << the_map.at(val) << std::endl;

    return result;
}

int main( ){

    int val = 5;

    std::unordered_map<int, int> the_map;

    std::cout << func(the_map, val) << std::endl;

}