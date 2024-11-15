#include <iostream>
#include <vector>
#include <stack>
int main()
{

    std::vector<int> the_vec = {10, 7, 15, 22, 7, -4, 18};
    std::stack<int> data_stack;
    std::stack<int> min_stack;
    std::stack<int> max_stack;

    data_stack.push( the_vec.at(0) );
    min_stack.push( the_vec.at(0) );
    max_stack.push( the_vec.at(0) );

    std::cout << data_stack.top() << " " << min_stack.top() << " " << max_stack.top() << std::endl;

    for( long unsigned int iter = 1; iter < the_vec.size(); ++iter ){

        if( min_stack.top() >= the_vec.at(iter) )
            min_stack.push( the_vec.at(iter) );

        if( max_stack.top() <= the_vec.at(iter) )
            max_stack.push( the_vec.at(iter) );

        data_stack.push( the_vec.at(iter) );

        std::cout << data_stack.top() << " " << min_stack.top() << " " << max_stack.top() << std::endl;
    }

    while( !data_stack.empty() ){

        if( data_stack.top() == min_stack.top() )
            min_stack.pop();

        if( data_stack.top() == max_stack.top() )
            max_stack.pop();

        data_stack.pop();

        if( !data_stack.empty() ){
            std::cout << data_stack.top() << " " << min_stack.top() << " " << max_stack.top() << std::endl;
        }
    }
    return 0;
}
