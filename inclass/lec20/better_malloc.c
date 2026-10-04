#include <stdio.h>
#include <stdlib.h>

/* function prototypes */

/* Step 1a - Allocate the memory function declaration */

/* Step 2a - Print the memory function declaration */

/* Step 3a - Free the Memory function declaration */


int main()
{

  /* Variables */
   int* int_dyn_arr;
   long unsigned int num_elements ;
   long unsigned int iterator;
   int factorial;


   fprintf( stdout, "Enter number of elements in integer values (greater than 0): ") ;
   fscanf( stdin, "%lu", &num_elements) ;

   /* Check for memory leak */
   if (num_elements == 0){
      fprintf(stderr, "Must be greater than 0\n") ;
      exit(-1);
   }

   /* 1c - Call the memory allocation function in main */


   /* Lets use the memory as an arrray */
   int_dyn_arr[0] = 1;
   factorial = 2;
   for (iterator = 1; iterator < num_elements; ++iterator){

      int_dyn_arr[iterator] = factorial * int_dyn_arr[iterator-1] ;
      ++factorial;

   }

   /* 2c - Print the memory addresses and data */


   /* 3c - Free the memory */


   return 0;
}


/* Step 1b - Allocate the memory function definition */


/* Step 2b - Print the memory function definition */


/* Step 3b - Free the Memory function definition */
