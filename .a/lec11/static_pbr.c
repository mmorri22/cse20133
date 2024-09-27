#include <stdio.h>

/* Put the compiler directive here */

/* When we copy to static_basic_prb.c, put the function declaration */
void print_array( int int_array_pa[], long unsigned int array_len_pa );

int main(){

  /* Allocate the static integer values */
  int int_array[] = {22, 17, -15, 8, 2, 15};
  long unsigned int array_len = 6;

  fprintf( stdout, "In main - %p\n", int_array );

  print_array( int_array, array_len );

  return 0;
}

/* When we copy to static_basic_prb.c, put the function definition */
void print_array( int int_array_pa[], long unsigned int array_len_pa ){

  fprintf( stdout, "In print_array - %p %p\n", int_array_pa, &int_array_pa );

  /* Iterate through the array and print the values */
  long unsigned int iter;
  for( iter = 0; iter < array_len_pa; ++iter ){

    fprintf( stdout, "int_array_pa[%lu] = %d at %p\n", iter, int_array_pa[iter], &int_array_pa[iter] );

  }

}