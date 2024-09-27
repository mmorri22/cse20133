#include <stdio.h>

/* Put the compiler directive here */
#define ARRAY_LEN 6

/* When we copy to static_basic_prb.c, put the function declaration */

void print_arrays( int int_array[], char char_array[], long unsigned int char_array_len );

int main(){

  /* Allocate the static integer values */
  int int_array[] = {12, 16, -22, 19, 5, 11};

  char char_array[] = "Go Irish!";

  long unsigned int char_array_len = 9;

  /* Iterate through the array and print the values */
  fprintf( stdout, "%p %p %p %p\n", int_array, &int_array, char_array, &char_array );

  fprintf( stdout, "%p %lu\n", &char_array_len, char_array_len);

  print_arrays( int_array, char_array, char_array_len );

  return 0;
}

/* When we copy to static_basic_prb.c, put the function definition */
void print_arrays( int int_array[], char char_array[], long unsigned int char_array_len ){

  fprintf( stdout, "%p %p %p %p\n", int_array, &int_array, char_array, &char_array );

  int iter = 0;

  fprintf( stdout, "%p %d\n", &iter, iter );

  for(iter = 0; iter < ARRAY_LEN; iter++){

    fprintf( stdout, "%d %p %d\n", iter, &int_array[iter], int_array[iter]);
  }

  for( iter = 0; iter < (int)char_array_len; iter++){
    fprintf( stdout, "%d %p %c\n", iter, &char_array[iter], char_array[iter]);
  }

}