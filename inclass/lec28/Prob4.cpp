#include <iostream>

void func( std::pair<int, int> the_pair ){

    std::cout << the_pair.first << " " << the_pair.second << std::endl;
    
    if( the_pair.first == 0 ){
        int temp = the_pair.first;
        the_pair.first = the_pair.second;
        the_pair.second = temp;
        return;
    }
    
    the_pair.first--;
    the_pair.second++;
    
    func( the_pair );
    
    the_pair.first++;
    the_pair.second++;
    
    std::cout << the_pair.first << " " << the_pair.second << std::endl;
}

int main(){

    std::pair<int, int> the_pair( {4, 10} );
    func( the_pair );
    return 0;
    
}
