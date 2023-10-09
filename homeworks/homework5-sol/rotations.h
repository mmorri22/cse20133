#ifndef ROTATIONS_H
#define ROTATIONS_H

/********************************************
 * Function Name: get_inputs
 * Pre-Conditions: long unsigned int size, int* rotate_array
 * Post-Conditions: return type void but will fill the array
 *
 * Takes in values for the dynamic array
 *******************************************/
 void get_inputs(long unsigned int size, int* rotate_array);

 /********************************************
 * Function Name: void rotate_left
 * Pre-Conditions: long unsigned int size, long unsigned int num_rotations, int* rotate_array
  * Post-Conditions: return type void but will print the rotated array
  *
  * Print the array before and after a given rotation left
  *******************************************/
  void rotate_left(long unsigned int size, long unsigned int num_rotations, int* rotate_array);

  /********************************************
   * Function Name: void rotate_right
   * Pre-Conditions: long unsigned int size, long unsigned int num_rotations, int* rotate_array
   * Post-Conditions: return type void but will print the rotated array
   *
   * Print the array before and after a given rotation right
   *******************************************/
   void rotate_right(long unsigned int size, long unsigned int num_rotations, int* rotate_array);

#endif
