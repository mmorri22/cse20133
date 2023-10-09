 #include "rotations.h"

  int main()
  { /*Define the array size the user will give*/
    long unsigned int size;
    /*Define the direction the user will give*/
    char direction;
    /*Define the number of rotations the user will give*/
    long unsigned int num_rotations;

    /*Define user input for whether to continue*/
    int userContinue;

    /*Run this at least once and then continue running while user keeps asking*/
    do
    {
      /*Tell the user what they need to provide*/
      fprintf(stdout,"Enter the size, number of rotations, and direction: \n");

      /*Get input from user*/
      if( fscanf(stdin, "%lu %lu %c", &size, &num_rotations, &direction) ) {}

	     fprintf( stdout, "%lu %lu %c\n", size, num_rotations, direction );

      /*Dynamically allocate the memory for the array*/
      int* rotate_array = (int *)malloc(size*sizeof(int));

      /*Call get_inputs to get user input*/
      get_inputs(size, rotate_array);

      if (direction == 'L')
      {
        rotate_left(size, num_rotations, rotate_array);
      }

      if (direction == 'R')
      {
        rotate_right(size, num_rotations, rotate_array);
      }

      /*Free the memory we allocated*/
      free(rotate_array);

      fprintf(stdout,"Do you wish to continue? (1 for yes, 2 for no): ");
      fscanf(stdin, "%d", &userContinue);

    } while(userContinue == 1);

    return 0;
  }
