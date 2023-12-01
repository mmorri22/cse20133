#ifndef PIZZA_H
#define PIZZA_H

#include "pizza.h"

#include <iostream>
#include <cstdlib>
#include <unistd.h>     // Interface with the POSIX API
#include <pthread.h>    // Pthread library

#define COUT std::cout
#define ENDL std::endl

//  Create the input thread struct 
typedef struct thread_func_args{
	
	pthread_t curr_tid;
    int kid_id;
    int curr_slices;
    int* pizza_ptr;
	
}thread_func_args;

// pass a void pointer to the function, and return a void pointer

void* thread_func( void* inputs );

void create_parallel_threads( thread_func_args** thread_inputs, long unsigned int num_kids, int* global_int_ptr );

void join_threads( thread_func_args** thread_inputs, long unsigned int num_kids );

void free_threads( thread_func_args** thread_inputs, long unsigned int num_kids );

#endif