#include <stdio.h>

/* Put the compiler directive here */

/* When we copy to static_basic_prb.c, put the function declaration */

int main(){

  /* Allocate the static integer values */
  int int_array[] = {22, 17, -15, 8, 2, 15};
  long unsigned int array_len = 6;

  /* Iterate through the array and print the values */
  long unsigned int iter;
  for( iter = 0; iter < array_len; ++iter ){

    fprintf( stdout, "int_array[%lu] = %d at %p\n", iter, int_array[iter], &int_array[iter] );

  }

  return 0;
}

/* When we copy to static_basic_prb.c, put the function definition */
