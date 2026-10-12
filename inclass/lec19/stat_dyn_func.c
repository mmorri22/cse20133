/* Step 1 - Write the required libraries for printing and dynamic malloc */


/* Step 2 - Create a compiler directive for a size of 5 elements */

void print_dyn(  long unsigned int dyn_arr_len, int* dyn_int_array );

void print_stat( double stat_double_array[] );

int main( void ){

  /* Step 4 - Create a static double array with five elements */
  

  /* Step 5a - Create a variable for the size of the dynamic array */
  

  /* Step 5b - Read in the dynamic array size using fscanf */
  fprintf(stdout, "Enter the length of the dynamic array: ")

  

  /* Step 5c - Print the location and value of this variable */
  

  /* Step 5d - Dynamically allocate an int array using the size */
  

  /* Step 6 - Read in the number of values using fscanf into the dynamic array */
  long unsigned int iter;
  
  /* Step 7 - Print the address and values of each location in the dynamic array */
  /* Step 7.1 - Location and value of the  containing the base address */
  

  /* Step 8 - Call print_dyn */
  

  /* Step 9 - Call print_stat */
  

  /* Step 5e - Free the Dynamic Array */
  

  /* Step 3 - Now that we have #include <stdlib.h>, use compiler directive EXIT_SUCCESS for return */
  
}


void print_dyn(  long unsigned int dyn_arr_len, int* dyn_int_array ){

  fprintf( stdout, "In func dyn_int_array = %p at %p\n", dyn_int_array, &dyn_int_array );

  /* Step 7.2 - Location and value of each element in the dynamic array */


}

void print_stat( double stat_double_array[] ){

  fprintf( stdout, "In func stat_double_array = %p at %p\n", stat_double_array, &stat_double_array );

  /* Step 7.3 - Location and value of each element in the static array */

}
