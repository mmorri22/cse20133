#include <iostream>
#include <stack>

int main()
{

    std::stack<int> int_stack;

    for( int iter = 0; iter < 17; ++iter ){

        int_stack.push( iter );

    }

    while( !int_stack.empty() ){

        // Read from the top element
        std::cout << int_stack.top() << " ";
        
        // Pop the top element
        int_stack.pop();
    }
    std::cout << std::endl;

    return 0;
}