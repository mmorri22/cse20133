#include <iostream>
#include <vector>

void func( std::vector<int> the_vec, std::pair<int, int>& the_pair, long unsigned int val_1 ){
    
    long unsigned int val_2 = the_vec.size() - val_1 - 1;
    the_pair.first = the_vec.at(val_1);
    the_pair.second = the_vec.at(val_2);
    
    std::cout << the_pair.first << " " << the_pair.second << std::endl;
    the_vec.at(val_1) = the_pair.second;
    the_vec.at(val_2) = the_pair.first;
    
}

void print_vec( std::vector<int>& the_vec ){
    
    for( long unsigned int iter = 0; iter < the_vec.size(); ++iter ){
        std::cout << the_vec.at(iter) << " ";
    }
    std::cout << std::endl;
}

int main(){
    
    std::pair<int, int> the_pair;
    std::vector<int> the_vec = {22, 17, 15, 31, 9, -21, 18, 45};
    
    for( long unsigned int iter = 0; iter < the_vec.size() / 2; ++iter )
        func( the_vec, the_pair, iter );
    
    print_vec( the_vec );
    
    return 0;
}