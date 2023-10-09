#include "rotations.h"
#include <stdio.h>

void get_inputs(long unsigned int size, int* rotate_array)
{
  /*Define what the user inout will be*/
  int userInt;

  /*Tell the user what to do*/
  fprintf(stdout,"Input the %lu values:\n",size);

  /*Take in the user input, put in the array, and print*/
  for (long unsigned int readCount = 0; readCount < size; readCount++)
  {
    fprintf(stdout,"Value at [%lu]: ", readCount);
    fscanf(stdin, "%d", &userInt);
    rotate_array[readCount] = userInt;
  }
}

void rotate_left(long unsigned int size, long unsigned int num_rotations, int* rotate_array)
{
  /*Print the current state of the array*/
  fprintf(stdout,"Before rotation:\n");

  for (long unsigned int beforeCount = 0; beforeCount < size; beforeCount++)
  {
    fprintf(stdout, "%d at %p\n", rotate_array[beforeCount], &rotate_array[beforeCount]);
  }

  /*Define size mod num_rotation or num_rotations mod size depending on which is larger*/
  long unsigned int modulus;

  if (size >= num_rotations && num_rotations != 0)
  {
    modulus = size - num_rotations;
  }
  else
  {
    modulus = size - (num_rotations % size);
  }

  fprintf(stdout,"After Rotation:\n");

  for (long unsigned int afterCount = 0; afterCount < size; afterCount++)
  {
    if (afterCount < modulus)
    {
      fprintf(stdout,"%d at %p\n", rotate_array[size-modulus+afterCount], &rotate_array[size-modulus+afterCount]);
    }
    else
    {
      fprintf(stdout,"%d at %p\n", rotate_array[afterCount-modulus], &rotate_array[afterCount-modulus]);
    }
  }
}

void rotate_right(long unsigned int size, long unsigned int num_rotations, int* rotate_array)
{
  /*Print the current state of the array*/
  fprintf(stdout,"Before rotation:\n");

  for (long unsigned int beforeCount = 0; beforeCount < size; beforeCount++)
  {
    fprintf(stdout, "%d at %p\n", rotate_array[beforeCount], &rotate_array[beforeCount]);
  }

  /*Define size mod num_rotation or num_rotations mod size depending on which is larger*/
  long unsigned int modulus;

  if (size >= num_rotations && num_rotations != 0)
  {
    modulus = size - num_rotations;
  }
  else
  {
    modulus = size - (num_rotations % size);
  }

  fprintf(stdout,"After Rotation:\n");
  fprintf(stdout,"modulus is %lu\n",modulus);
  for (long unsigned int afterCount = 0; afterCount < size; afterCount++)
  {
    if (afterCount < (size-modulus))
    {
      fprintf(stdout,"%d at %p\n", rotate_array[afterCount+modulus], &rotate_array[afterCount+modulus]);
    }
    else
    {
      fprintf(stdout,"%d at %p\n", rotate_array[-size+modulus+afterCount], &rotate_array[-size+modulus+afterCount]);
    }
  }
}
