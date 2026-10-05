/* Step 1 - Write the required libraries for printing and dynamic malloc */
#include <stdio.h>
#include <stdlib.h>

/* Step 2 - Create a compiler directive for a size of 5 elements */
#define ELEMENT_SIZE 5

void print_dyn( long unsigned int dyn_arr_len, double* dyn_double_array );

void print_stat( double stat_double_array[] );

int main( void ){

  /* Step 4 - Create a static integer array with five elements */
  double stat_double_array[ELEMENT_SIZE] = {10.1, -15.7, -7.6, 22, 6.51};

  /* Step 5a - Create a variable for the size of the dynamic array */
  long unsigned int dyn_arr_len;

  /* Step 5b - Read in a size using fscanf */
  if( fscanf( stdin, "%lu", &dyn_arr_len ) == -1 ){
    return EXIT_FAILURE;
  }

  /* Step 5c - Print the location and value of this variable */
  fprintf( stdout, "%lu at %p\n", dyn_arr_len, &dyn_arr_len );

  /* Step 5d - Dynamically allocate an int array using the size */
  double* dyn_double_array = (double *)malloc( dyn_arr_len*sizeof(double) );

  /* Step 6 - Read in the number of values using fscanf into the dynamic array */
  long unsigned int iter;
  for(iter = 0; iter < dyn_arr_len; ++iter){

      double temp;

      if( fscanf( stdin, "%lf", &temp ) == -1 ){
        return EXIT_FAILURE;
      }

      dyn_double_array[iter] = temp;

  }

  /* Step 7 - Print the address and values of each location in the dynamic array */
  /* Step 7.1 - Location and value of the register containing the base address */
  fprintf( stdout, "In main dyn_double_array = %p at %p\n", dyn_double_array, &dyn_double_array );

  print_dyn( dyn_arr_len, dyn_double_array );

  print_stat( stat_double_array );

  /* Step 8 - Free the Dynamic Array */
  free(dyn_double_array);

  /* Step 3 - Now that we have #include<stdlib.h>, use compiler directive EXIT_SUCCESS for return */
  return EXIT_SUCCESS;
}


void print_dyn( long unsigned int dyn_arr_len, double* dyn_double_array ){

  fprintf( stdout, "In func dyn_double_array = %p at %p\n", dyn_double_array, &dyn_double_array );

  /* Step 7.2 - Location and value of each element in the dynamic array */
  long unsigned int iter;
  for(iter = 0; iter < dyn_arr_len; ++iter){

    fprintf( stdout, "dyn_double_array[%lu] = %lf at %p\n", iter, dyn_double_array[iter], &dyn_double_array[iter] );
  }

}

void print_stat( double stat_double_array[] ){

  fprintf( stdout, "In func stat_double_array = %p at %p\n", stat_double_array, &stat_double_array );

  long unsigned int iter;
  for(iter = 0; iter < ELEMENT_SIZE; ++iter ){
    fprintf( stdout, "stat_double_array[%lu] = %lf at %p\n", iter, stat_double_array[iter], &stat_double_array[iter] );
  }

}
