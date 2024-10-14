#include <stdio.h>
#include <stdlib.h>

/* function prototypes */

/* Step 1a - Allocate the memory function declaration */
void alloc_memory( long unsigned int num_elements, int** dyn_int_array );

/* Step 2a - Print the memory function declaration */
void print_memory( long unsigned int num_elements, int* dyn_arr_ptr );

/* Step 3a - Free the Memory function declaration */
void free_memory( int** dyn_int_array );

int main()
{

  /* Variables */
   int* int_dyn_arr;
   long unsigned int num_elements ;
   long unsigned int iterator;
   int factorial;


   fprintf( stdout, "Enter number of elements in integer values (greater than 0): ") ;
   if( fscanf( stdin, "%lu", &num_elements) == -1 ){
      return EXIT_FAILURE;
   }

   /* Check for memory leak */
   if (num_elements == 0){
      fprintf(stderr, "Must be greater than 0\n") ;
      exit(-1);
   }

   /* 1c - Call the memory allocation function in main */
   alloc_memory( num_elements, &int_dyn_arr );

   fprintf( stdout, "Main - %p at %p\n", int_dyn_arr, &int_dyn_arr );

   /* Lets use the memory as an arrray */
   int_dyn_arr[0] = 1;
   factorial = 2;
   for (iterator = 1; iterator < num_elements; ++iterator){

      int_dyn_arr[iterator] = factorial * int_dyn_arr[iterator-1] ;
      ++factorial;

   }

   /* 2c - Print the memory addresses and data */
   print_memory( num_elements, int_dyn_arr );

   /* 3c - Free the memory */
   free_memory( &int_dyn_arr );

   return 0;
}


/* Step 1b - Allocate the memory function definition */
void alloc_memory( long unsigned int num_elements, int** dyn_int_array ){

   fprintf( stdout, "before - %p %p %p\n", *dyn_int_array, dyn_int_array, &dyn_int_array );

   *dyn_int_array = (int *)malloc( num_elements * sizeof(int) );

   fprintf( stdout, "after - %p %p %p\n", *dyn_int_array, dyn_int_array, &dyn_int_array );

}

/* Step 2b - Print the memory function definition */
void print_memory( long unsigned int num_elements, int* dyn_arr_ptr ){

   long unsigned int iter;
   for( iter = 0; iter < num_elements; ++iter ){

      fprintf( stdout, "%d at %p\n", dyn_arr_ptr[iter], &dyn_arr_ptr[iter]);
   }
}

/* Step 3b - Free the Memory function definition */
void free_memory( int** dyn_int_array ){
   free( *dyn_int_array );
}