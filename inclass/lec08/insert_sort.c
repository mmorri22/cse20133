#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* returns a random number within certain bounds */
int get_random_int (int min, int max);

/* fills an array with random integers using the get_random_int function */
void fill_array(int int_array[], long unsigned int length, int min, int max);

/* sorts the array of random numbers using insertion sort */
void insertion_sort(int int_array[], long unsigned int length);

/* prints the values of the array */
void print_array(int int_array[], long unsigned int length);

int main(){

  int max = 100;
  int min = 1;

  long unsigned int length = 10;
  int int_array[length];

  fill_array(int_array, length, min, max);

  fprintf(stdout, "Unsorted array\n");
  fprintf(stdout, "Printing array...\n");
  print_array(int_array, length);

  insertion_sort(int_array, length);

  fprintf(stdout, "Sorted array\n");
  fprintf(stdout, "Printing array...\n");
  print_array(int_array, length);

  return 0;

}

int get_random_int (int min, int max){

  int random_int = rand();
  random_int = random_int % (max - min + 1) + min;
  return random_int;

}


void fill_array(int int_array[], long unsigned int length, int min, int max){

  /* Year 2038 Error */
  srand( (unsigned int)time(NULL) );

  long unsigned int iter;

  for (iter = 0; iter < length; ++iter) {
    int_array[iter] = get_random_int(min, max);
  }

}

/******************************************************************************/

void insertion_sort(int int_array[], long unsigned int length){

  long unsigned int last_sorted;
  long unsigned int first_unsorted;
  int test_index;

  /* Work together to perform sorting */
  
}

/******************************************************************************/

void print_array(int int_array[], long unsigned int length){

  long unsigned int iter;

  for (iter = 0; iter < length; ++iter) {
    fprintf(stdout, "%d ", int_array[iter]);
  }

  fprintf(stdout, "\n");
}
