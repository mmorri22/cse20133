/* Step 1 - Write the required libraries for printing and dynamic malloc */
#include <stdio.h>
#include <stdlib.h>

/* Step 2 - Create a compiler directive for a size of 5 elements */
#define ELEMENT_SIZE 5

void print_dyn( long unsigned int dyn_arr_len, int* dyn_int_array );

void print_stat( int stat_int_array[] );

int main( void ){

  /* Step 4 - Create a static integer array with five elements */
  int stat_int_array[ELEMENT_SIZE] = {10, 15, -7, 22, 6};

  /* Step 5a - Create a variable for the size of the dynamic array */
  long unsigned int dyn_arr_len;

  /* Step 5b - Read in a size using fscanf */
  fscanf( stdin, "%lu", &dyn_arr_len );

  /* Step 5c - Print the location and value of this variable */
  fprintf( stdout, "%lu at %p\n", dyn_arr_len, &dyn_arr_len );

  /* Step 5d - Dynamically allocate an int array using the size */
  int* dyn_int_array = (int *)malloc( dyn_arr_len*sizeof(int) );

  /* Step 6 - Read in the number of values using fscanf into the dynamic array */
  long unsigned int iter;
  for(iter = 0; iter < dyn_arr_len; ++iter){

      int temp;
      fscanf( stdin, "%d", &temp );
      dyn_int_array[iter] = temp;

  }

  /* Step 7 - Print the address and values of each location in the dynamic array */
  /* Step 7.1 - Location and value of the register containing the base address */
  fprintf( stdout, "In main dyn_int_array = %p at %p\n", dyn_int_array, &dyn_int_array );

  print_dyn( dyn_arr_len, dyn_int_array );

  int stat_int_array[ELEMENT_SIZE] = {206, 101, -18, 34, 5};
  print_stat( stat_int_array );

  /* Step 8 - Free the Dynamic Array */
  free(dyn_int_array);

  /* Step 3 - Now that we have #include<stdlib.h>, use compiler directive EXIT_SUCCESS for return */
  return EXIT_SUCCESS;
}


void print_dyn( long unsigned int dyn_arr_len, int* dyn_int_array ){

  fprintf( stdout, "In func dyn_int_array = %p at %p\n", dyn_int_array, &dyn_int_array );

  /* Step 7.2 - Location and value of each element in the dynamic array */
  long unsigned int iter;
  for(iter = 0; iter < dyn_arr_len; ++iter){

    fprintf( stdout, "dyn_int_array[%lu] = %d at %p\n", iter, dyn_int_array[iter], &dyn_int_array[iter] );
  }

}

void print_stat( int stat_int_array[] ){

  fprintf( stdout, "In func stat_int_array = %p at %p\n", stat_int_array, &stat_int_array );

  long unsigned int iter;
  for(iter = 0; iter < ELEMENT_SIZE; ++iter ){
    fprintf( stdout, "stat_int_array[%lu] = %d at %p\n", iter, stat_int_array[iter], &stat_int_array[iter] );
  }

}
