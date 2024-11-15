#include <iostream>
#include <vector>
#include <stack>

int main(){

    std::vector<int> the_vec(4, 10);

    for( int iter = 0; iter < 5; ++iter ){
        the_vec.push_back( iter );
    }

    std::stack<int> the_stack;

    for( long unsigned int iter = 0; iter < the_vec.size(); ++iter ){
        std::cout << the_vec.at(iter) << " ";
        the_stack.push( the_vec.at(iter) );
    }
    std::cout << std::endl;

    while( !the_stack.empty() ){
        std::cout << the_stack.top() << " ";
        the_stack.pop();
    }

    std::cout << std::endl;
    return 0;
}
