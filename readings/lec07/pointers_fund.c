#include <stdio.h>

int main(){

  /* Prints the location of stdout on the stack for this run */
  fprintf(stdout, "stdout is located at %p\n", stdout);

  /* Prints the register address and hex value of an int */
  int the_int = -25;
  fprintf(stdout, "the_int = %d (%x) at location %p\n", the_int, the_int, &the_int);

  /* Prints the register address and hex value of an unsigned int */
  unsigned int the_uint = 25;
  fprintf(stdout, "the_uint = %u (%x) at location %p\n", the_uint, the_uint, &the_uint);

  /* Prints the register address and IEEE 754 of a double to 13 decimal places */
  double the_double = 3.1415926535897;
  fprintf(stdout, "the_double = %.13lf (%la) at location %p\n", the_double, the_double, &the_double);

  return 0;
}
