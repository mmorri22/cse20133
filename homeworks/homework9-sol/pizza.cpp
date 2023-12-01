#include "pizza.h"

pthread_mutex_t Lock = PTHREAD_MUTEX_INITIALIZER;

// pass a void pointer to the function, and return a void pointer
void* thread_func( void* inputs ){
	
	// Cast the void* back to a struct pointer inside the function
	thread_func_args* func_inputs = (thread_func_args *)inputs;
	
    while( *(func_inputs->pizza_ptr) > 0 ){

	    // lock the mutex
	    pthread_mutex_lock(&Lock);
	
        if( ( *(func_inputs->pizza_ptr) > 18 ) && ( func_inputs->curr_slices < 2 ) ){

            int num_slices = 2 - func_inputs->curr_slices;

            *(func_inputs->pizza_ptr) -= num_slices;

            func_inputs->curr_slices += num_slices; 

            COUT << "Kid " << func_inputs->kid_id << " ate " << num_slices << " slices and has eaten " << func_inputs->curr_slices << " slices. There are ";
            COUT << *(func_inputs->pizza_ptr) << " total slices remaining." << ENDL;

        }else if( ( *(func_inputs->pizza_ptr) <= 18 ) && ( *(func_inputs->pizza_ptr) > 3 ) && ( func_inputs->curr_slices < 3 ) ){

            *(func_inputs->pizza_ptr) -= 1;

            func_inputs->curr_slices++;

            COUT << "Kid " << func_inputs->kid_id << " ate 1 slice and has eaten " << func_inputs->curr_slices << " slices. There are ";
            COUT << *(func_inputs->pizza_ptr) << " total slices remaining." << ENDL;

        }else if( ( *(func_inputs->pizza_ptr) <= 3 ) && ( *(func_inputs->pizza_ptr) >= 1 ) ){

            *(func_inputs->pizza_ptr) -= 1;

            func_inputs->curr_slices++;

            COUT << "Else case: Kid " << func_inputs->kid_id << " has eaten " << func_inputs->curr_slices << " slices. There are ";
            COUT << *(func_inputs->pizza_ptr) << " total slices remaining." << ENDL;

        }
	
	    // Unlock the mutex
	    pthread_mutex_unlock(&Lock);

        // make the thread wait 1 millisecond
        sleep(1);

    }
	
	// Step 4 - Return NULL
	return NULL;
}

void create_parallel_threads( thread_func_args** thread_inputs, long unsigned int num_kids, int* global_int_ptr ){
	
	long unsigned int iter;
	
	for( iter = 0; iter < num_kids; ++iter ){
		
		thread_inputs[ iter ] = (thread_func_args*)calloc( 1, sizeof(thread_func_args) );
		
		thread_inputs[ iter ]->kid_id = (int)iter;

        thread_inputs[ iter ]->curr_slices = 0;
		
		thread_inputs[ iter ]->pizza_ptr = global_int_ptr;

		pthread_create( &(thread_inputs[ iter ]->curr_tid), NULL, thread_func, (void *)(thread_inputs[ iter ]) );
		
	}	
	
}

void join_threads( thread_func_args** thread_inputs, long unsigned int num_kids ){
	
	long unsigned int iter;
	
	for ( iter = 0; iter < num_kids; ++iter ) {
		
		pthread_join( thread_inputs[ iter ]->curr_tid,  NULL );

	}	
	
}

void free_threads( thread_func_args** thread_inputs, long unsigned int num_kids ){
	
	long unsigned int iter;
	
	for( iter = 0; iter < num_kids; ++iter ){
		
		free( thread_inputs[ iter ] );

	}
	
}