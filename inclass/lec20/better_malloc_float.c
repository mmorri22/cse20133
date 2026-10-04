#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void alloc_memory(long unsigned int array_len, float** dyn_arr_ptr);

void print_memory(long unsigned int array_len, float* dyn_arr_ptr);

void free_memory(float** dyn_arr_ptr);

int main()
{

  /* Variables */
   float* int_dyn_arr;
   long unsigned int num_elements ;
   long unsigned int iterator;
   float factorial;


   fprintf( stdout, "Enter number of elements in integer values (greater than 0): ") ;
   fscanf( stdin, "%lu", &num_elements) ;

   /* Check for memory leak */
   if (num_elements == 0){
      fprintf(stderr, "Must be greater than 0\n") ;
      exit(-1);
   }

   /* How do we pass a pointer to a pointer to allocate memory? */
   alloc_memory(num_elements, &int_dyn_arr);

   /* Lets use the memory as an arrray */
   int_dyn_arr[0] = 1;
   factorial = (float)2;
   for (iterator = 1; iterator < num_elements; ++iterator){

      int_dyn_arr[iterator] = factorial * int_dyn_arr[iterator-1] ;
      ++factorial;

   }

   /* Print the memory addresses and data */
   print_memory(num_elements, int_dyn_arr);

   /* Free the memory */
   free_memory( &int_dyn_arr );

   return 0;
}


void alloc_memory (long unsigned int array_len, float **dyn_arr_ptr )
{

  /* Allocate the memory */
   *dyn_arr_ptr = (float *) malloc( array_len * sizeof(float) ) ;

   /* Check for memory leak */
   if (*dyn_arr_ptr == NULL)
   {
      fprintf(stderr, "Oops, we're out of memory\n") ;
      exit(-1);
   }
}


void print_memory(long unsigned int array_len, float* dyn_arr_ptr){

  /* Print out contents of the array */
  long unsigned int iterator;
  for (iterator = 0; iterator < array_len; ++iterator){
    fprintf( stdout, "dyn_arr_ptr[%lu] = %e at %p\n", iterator, dyn_arr_ptr[iterator], &dyn_arr_ptr[iterator]);
  }
}

void free_memory(float** dyn_arr_ptr){

  /* Free the memory - Be sure to de-reference! */
  free(*dyn_arr_ptr) ;

}
