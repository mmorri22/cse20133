/*******************************
 * File name: max_stack.h 
 * Author: Matthew Morrison
 * E-mail: matt.morrison@nd.edu 
 * 
 * This file contains the template class
 * for a stack with a max and a min stack.
 * ****************************/

#ifndef MAX_STACK_H
#define MAX_STACK_H

#include <stack>

template <typename T>
class max_stack {
    
	private:
		// Data, Max, and Minimum Stacks
		std::stack<T> data;
		std::stack<T> max_data;
		std::stack<T> min_data;
    
    public:
    
        // Counters for size to report
        // Don't need to unstack to get stack size.
        size_t data_size = 0;
        size_t max_size = 0;
        size_t min_size = 0;
		
		max_stack() : data(), max_data(), min_data() {}
 
        /*********************************************
         * Function Name: empty
         * Preconditions: none 
         * Postconditions: bool 
         * This function returns a boolean indicating
         * if the main data stack is empty
         * ******************************************/
    	bool empty() const { 
    	    return data.empty(); 
    	}

        /*********************************************
         * Function Name: top
         * Preconditions: none 
         * Postconditions: const T& 
         * This function returns the value of the top element
         * of the stack without popping the stack 
         * ******************************************/    	
        const T& top() const { 
            return data.top(); 
        }

        /*********************************************
         * Function Name: push
         * Preconditions: const T&  
         * Postconditions: none 
         * This function pushes the value on the top 
         * of the data stack. If it is <= to the minimum,
         * or if >= to the max, then 
         * ******************************************/          
        void push(const T& value) {
			
			std::cout << value << " ";
			
            data.push(value);   data_size++;
    
            if (max_data.empty() || value >= max_data.top()) {
                max_data.push(value);
                max_size++;
            } 
            
            if (min_data.empty() || value <= min_data.top()) {
                min_data.push(value);
                min_size++;
            } 
        }

        /*********************************************
         * Function Name: pop 
         * Preconditions: void
         * Postconditions: none 
         * This function pops the top value of the data 
         * stack, and if the value is equal to the max or 
         * min stack, it pops those values off as well.
         * ******************************************/           
        void pop() {
            if(data.top() == max_data.top()){
                std::cout << "Max found! " << data.top() << " popped." << std::endl;
                max_data.pop();
                max_size--;
            }
            
            if(data.top() == min_data.top()){
                std::cout << "Min found! " << data.top() << " popped." << std::endl;
                min_data.pop();
                min_size--;
            }
                
            data.pop(); data_size--;

        }

        /*********************************************
         * Function Name: max() 
         * Preconditions: none 
         * Postconditions: const T& 
         * This function returns the value of the maximum
         * element in the stack.
         * ******************************************/           
        const T& max() const { 
            return max_data.top(); 
        }

        /*********************************************
         * Function Name: min() 
         * Preconditions: none 
         * Postconditions: const T& 
         * This function returns the value of the minimum
         * element in the stack.
         * ******************************************/           
        const T& min() const { 
            return min_data.top(); 
        }
};

#endif