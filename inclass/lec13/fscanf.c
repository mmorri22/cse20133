#include <stdio.h>

#define BUFFER 50

int main(){

  int first_int;
  float first_float;
  double first_double;
  char first_string[BUFFER];

  /* Step 1 - Write fscanf to read in the values */
  fprintf( stdout, "Enter an integer, float, double, and a string: ");

  if( fscanf( stdin, "%d %f %lf %s", &first_int, &first_float,
    &first_double, first_string ) ) { }

  /* Step 2 - Write fprintf to print all the values */
  fprintf( stdout, "%d %f %lf %s\n", first_int, first_float,
    first_double, first_string);

  return 0;
}
