#include <stdio.h>
#include <stdlib.h>

/***********************************************************************************
 * Function Name: insert_dynamic_array
 * Preconditions: int* dyn_int_array, long unsigned int array_len, char* argv[]
 * Postconditions: Void
 * 
 * Takes in an allocated array of array_len, and reads through argv, converting the
 * command line arguments into integers, and passes the completed array by reference
 ************************************************************************************/
void insert_dynamic_array(int* dyn_int_array, long unsigned int array_len, char* argv[]);

/***********************************************************************************
 * Function Name: print_dyn_array
 * Preconditions: int* dyn_int_array, long unsigned int array_len
 * Postconditions: Void
 * 
 * Prints the addresses and values of the array
 ************************************************************************************/
void print_dyn_array(int* dyn_int_array, long unsigned int length);


int main( int argc, char* argv[] ){

  /* Step 1 - Example of Error Checking */
  if( argc < 2 ){
    fprintf( stderr, "Need more than one input\n" );

    return EXIT_FAILURE;
  }


  // Step 2-1 - Need to cast argc to long unsigned int
  // argc - 1 since the first argument is the ./argc_argv argument
  long unsigned int array_len = (long unsigned int)(argc - 1) ;

  // Step 3 - Allocate the dynamic array
  int* dyn_int_array = (int *)malloc( array_len * sizeof(int) );

  /* Step 4-1 - Pass the array and argv into main */
  insert_dynamic_array(dyn_int_array, array_len, argv);

  // Step 5-1 - Print 
  print_dyn_array( dyn_int_array, array_len );

  // Step 2-2 - Free the dynamic array
  free( dyn_int_array );

  return EXIT_SUCCESS;

}

void insert_dynamic_array(int* dyn_int_array, long unsigned int array_len, char* argv[]){

  long unsigned int iter;

  // Step 4-2 - Convert every value except the initial executable using atoi
  for(iter = 0; iter < array_len; ++iter){
    dyn_int_array[iter] = atoi(argv[iter+1]);
  }
}


void print_dyn_array(int* dyn_int_array, long unsigned int length){

  long unsigned int iter;
  for(iter = 0; iter < length; ++iter){

    fprintf( stdout, "dyn_int_array[%lu] = %d at %p\n", iter, dyn_int_array[iter], &dyn_int_array[iter]);
  }

}
