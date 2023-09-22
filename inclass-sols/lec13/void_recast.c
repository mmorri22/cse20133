#include <stdio.h>
#include <stdlib.h>

int main()
{

  /* Step 1a - Allocate a length of four */
  long unsigned int array_len = 4;

  /* Step 1b - Allocate a void pointer array */
  void* void_array = malloc( array_len * sizeof(char) );

  /* Step 3 - Using pointer arithmetic and ASCII hex, save values A, B, C, D */
  *(char *)(void_array + 0*sizeof(char)) = 0x41; // 'A'
  *(char *)(void_array + 1*sizeof(char)) = 'B'; // 0x66
  *(char *)(void_array + 2*sizeof(char)) = 0x43; // 'B'
  *(char *)(void_array + 3*sizeof(char)) = 'D'; // 0x68

  /* Step 4 - Loop through and print addresses */

  fprintf( stdout, "%p %p\n", &void_array, void_array);

  long unsigned int iter;
  for( iter = 0; iter < array_len; ++iter){
    fprintf( stdout, "%c at %p\n", 
      *(char *)(void_array + iter*sizeof(char)),
      void_array + iter*sizeof(char) );
  }

  /* Step 6 - Cast the address to int and print the result */
  fprintf( stdout, "%d\n", *(int *)(void_array) );


  /* Step 1c - Free the void array*/
  free(void_array);

  return 0;
}
