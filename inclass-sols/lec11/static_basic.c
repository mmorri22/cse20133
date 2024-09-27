#include <stdio.h>

/* Put the compiler directive here */
#define ARRAY_LEN 6

/* When we copy to static_basic_prb.c, put the function declaration */

int main(){

  /* Allocate the static integer values */
  int int_array[] = {12, 16, -22, 19, 5, 11};

  char char_array[] = "Go Irish!";

  /* Iterate through the array and print the values */
  fprintf( stdout, "%p %p\n", int_array, char_array );

  int iter = 0;

  fprintf( stdout, "%p %d\n", &iter, iter );

  for(iter = 0; iter < ARRAY_LEN; iter++){

    fprintf( stdout, "%d %p %d\n", iter, &int_array[iter], int_array[iter]);
  }

  for( iter = 0; iter < 9; iter++){
    fprintf( stdout, "%d %p %c\n", iter, &char_array[iter], char_array[iter]);
  }

  return 0;
}

/* When we copy to static_basic_prb.c, put the function definition */
