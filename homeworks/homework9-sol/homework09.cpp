#include "pizza.h"

int main( void ){

    // Number of threads 
	long unsigned int num_kids = 15;

    // Integer to update 
	int pizza_slices = 48;

    COUT << "Initial Pizza Slices = " << pizza_slices << " for " << num_kids << " kids" << ENDL;

    // Create a struct with the inputs for the function
    thread_func_args** thread_inputs = (thread_func_args**)malloc( num_kids * sizeof(thread_func_args *) );

    // Create the parallel threads
	create_parallel_threads( thread_inputs, num_kids, &pizza_slices );

    // Join all threads
	join_threads( thread_inputs, num_kids );

    // Free the memory allocated to the structs
	free_threads( thread_inputs, num_kids );

    //Free the ** struct
	free( thread_inputs );
	
	pthread_exit( NULL );
	
	return EXIT_SUCCESS;

}