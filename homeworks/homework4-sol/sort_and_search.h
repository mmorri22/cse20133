#ifndef SORT_AND_SEARCH_H
#define SORT_AND_SEARCH_H

#include <stdio.h>

#define ARRAYSIZE 10

/********************************************
 * Function Name: fill_array
 * Pre-Conditions: int_array
 * Post-Conditions: return type void but will fill an array
 *
 * Fill an array with user input
 *******************************************/
 void fill_array(int int_array[]);

 /********************************************
  * Function Name: print_array
  * Pre-Conditions: int int_array
  * Post-Conditions: return type void but should print the array
  *
  * print an array
  *******************************************/
  void print_array(int int_array[]);

  /********************************************
   * Function Name: insertion_sort
   * Pre-Conditions: int int_array
   * Post-Conditions: return type void but should sort the array
   *
   * Perform insertion sort on a given array
   *******************************************/
  void insertion_sort(int int_array[]);

  /********************************************
   * Function Name: scan_value
   * Pre-Conditions: int* search_val
   * Post-Conditions: return type void but returns by reference
   *
   * Takes in a value from the user that can be searched for
   *******************************************/
   void scan_value(int* search_val);

   /********************************************
    * Function Name: binary_search
    * Pre-Conditions: int int_array, int value
    * Post-Conditions: the index of the desired value -1 to indicate a failure
    *
    * Uses binary search to look for a user-provided value
    *******************************************/
    int binary_search(int int_array[], int value);





#endif
