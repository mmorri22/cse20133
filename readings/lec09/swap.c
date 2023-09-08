#include <stdio.h>

/* Function Declarations */
void swap( int* ptr_x, int* ptr_y );

int main(){

  int swap_x = 10;
  int swap_y = 25;

  fprintf( stdout, "Before: swap_x = %d, swap_y = %d\n", swap_x, swap_y );

  swap( &swap_x, &swap_y );

  fprintf( stdout, "After : swap_x = %d, swap_y = %d\n", swap_x, swap_y );

  return 0;
}

/* Function Definitions */
void swap( int* ptr_x, int* ptr_y ){

    /* De-reference ptr_x to set the temp_val to swap_x */
    int temp_val = *ptr_x;

    /* Set the value at swap_x equal to the value at swap_y */
    *ptr_x = *ptr_y;

    /* Set the value at swap_y equal to temp_val */
    *ptr_y = temp_val;

}
