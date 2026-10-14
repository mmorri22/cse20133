#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void alloc_memory(long unsigned int array_len, long int** dyn_arr_ptr);

void print_memory(long unsigned int array_len, long int* dyn_arr_ptr);

void free_memory(long int** dyn_arr_ptr);

int main()
{

  /* Variables */
   long int* dyn_arr_ptr;
   long unsigned int num_elements ;
   long unsigned int iterator;
   long int factorial;


   fprintf( stdout, "Enter number of elements in integer values (greater than 0): ") ;
   if( fscanf( stdin, "%lu", &num_elements) == -1 ){
    return EXIT_FAILURE;
   }

   /* Check for memory leak */
   if (num_elements == 0){
      fprintf(stderr, "Must be greater than 0\n") ;
      exit(-1);
   }

   fprintf(stdout, "In main dyn_arr_ptray before alloc_memory - %p %p\n", &dyn_arr_ptr, dyn_arr_ptr );

   /* How do we pass a pointer to a pointer to allocate memory? */
   alloc_memory(num_elements, &dyn_arr_ptr);

   fprintf(stdout, "In main dyn_arr_ptray after alloc_memory - %p %p\n", &dyn_arr_ptr, dyn_arr_ptr );

   /* Lets use the memory as an arrray */
   dyn_arr_ptr[0] = 1;
   factorial = 2;
   for (iterator = 1; iterator < num_elements; ++iterator){

      dyn_arr_ptr[iterator] = factorial * dyn_arr_ptr[iterator-1] ;
      ++factorial;

   }

   /* Print the memory addresses and data */
   print_memory(num_elements, dyn_arr_ptr);

   /* Free the memory */
   free_memory( &dyn_arr_ptr );

   fprintf(stdout, "In main dyn_arr_ptray after free_memory - %p %p\n", &dyn_arr_ptr, dyn_arr_ptr );

   return 0;
}


void alloc_memory (long unsigned int array_len, long int **dyn_arr_ptr )
{

  /* Allocate the memory */
   *dyn_arr_ptr = (long int *) malloc( array_len * sizeof(long int) ) ;

   /* Check for memory leak */
   if (*dyn_arr_ptr == NULL)
   {
      fprintf(stderr, "Oops, we're out of memory\n") ;
      exit(-1);
   }

   fprintf(stdout, "In alloc memory - %p %p %p\n", &dyn_arr_ptr, dyn_arr_ptr, *dyn_arr_ptr );


}


void print_memory(long unsigned int array_len, long int* dyn_arr_ptr){

  /* Print out contents of the array */
  long unsigned int iterator;
  for (iterator = 0; iterator < array_len; ++iterator){
    fprintf( stdout, "dyn_arr_ptr[%lu] = %lu at %p\n", iterator, dyn_arr_ptr[iterator], &dyn_arr_ptr[iterator]);
  }
}

void free_memory(long int** dyn_arr_ptr){

  fprintf(stdout, "In free_memory before free - %p %p %p\n", &dyn_arr_ptr, dyn_arr_ptr, *dyn_arr_ptr );

  /* Free the memory - Be sure to de-reference! */
  free(*dyn_arr_ptr) ;

  fprintf(stdout, "In free_memory after free - %p %p %p\n", &dyn_arr_ptr, dyn_arr_ptr, *dyn_arr_ptr );

}
