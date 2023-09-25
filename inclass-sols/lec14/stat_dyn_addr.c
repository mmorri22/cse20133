/* Step 1 - Write the required memory elements for dynamic malloc */
#include <stdio.h>
#include <stdlib.h>

/* Step 2 - Create a compiler directive for a size of 4 element */
#define NUM_ELEMENTS 4

int main( void ){

  /* Step 4 - Create a static integer array with four elements */
  int static_array[NUM_ELEMENTS];
  static_array[0] = 17;
  static_array[1] = 45;
  static_array[2] = -18;
  static_array[3] = 31;

  /* Step 5a - Create a variable for the size of the dynamic array */
  long unsigned int dyn_array_len;

  /* Step 5b - Read in a size using fscanf */
  if(fscanf(stdin, "%lu", &dyn_array_len)){}

  /* Step 5c - Print the location and value of this variable */
  fprintf( stdout, "%p %lu\n", &dyn_array_len, dyn_array_len );

  /* Step 5d - Dynamically allocate an int array using the size */
  int* dyn_array = (int *)malloc( dyn_array_len * sizeof(int) );

  /* Step 6 - Read in the number of values using fscanf */
  long unsigned int iter;
  for( iter = 0; iter < dyn_array_len; ++iter ){

    // Lower Levels of Abstraction Version
    // if( fscanf(stdin, "%d", (int *)(dyn_array + iter*sizeof(int)) ) ){}

    // Higher Levels of Abstraction Version
    if( fscanf(stdin, "%d", &dyn_array[iter] ) ){}
  }

  /* Step 7 - Print the address and values of each location in the dynamic array */
  /* Step 7.1 - Location and value of the register containing the base address */
  for( iter = 0; iter < NUM_ELEMENTS; ++iter ){
    fprintf( stdout, "%d %p\n", static_array[iter], &static_array[iter]);
  }  

  /* Step 7.2 - Location and value of each element in the dynamic array */
  fprintf( stdout, "%p %p\n", &dyn_array, dyn_array );

  for( iter = 0; iter < dyn_array_len; ++iter){
    fprintf( stdout, "%d %p\n", dyn_array[iter], &dyn_array[iter]);
  }

  /* Step 8 - Free the Dynamic Array */
  free( dyn_array );


  /* Step 3 - Now that we have #include<stdlib.h>, use compiler directive EXIT_SUCCESS */
  return EXIT_SUCCESS;

}
