#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#define COUT std::cout
#define ENDL std::endl

void func( std::vector<int>& vec, std::stack<int> stack, std::queue<int>& queue, int iter ){
    
    if( iter == vec.size() ){
        stack.push(0);
        queue.push(0);
        return;
    }
    
    stack.push( vec.at(iter) );
    queue.push( vec.at(iter) );
    
    COUT << iter << " " << vec.at(iter) << " " << stack.top() << " " << queue.front() << ENDL;
    
    func( vec, stack, queue, iter + 1 );
    
    COUT << iter << " " << vec.at(iter) << " " << stack.top() << " " << queue.front() << ENDL;
    
    stack.pop();
    queue.pop();
    
}

int main(){
    
    std::vector<int> main_vec = {1, 2, 3, 4};
    std::queue<int> main_queue;
    std::stack<int> main_stack;
    
    func( main_vec, main_stack, main_queue, 0 );

    return 0;
}