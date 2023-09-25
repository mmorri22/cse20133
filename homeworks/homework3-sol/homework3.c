/*****************************
name: Answer Key
email: akey@nd.edu
file: main function for PC03
*****************************/

#include "means.h"

int main(){

  long unsigned int array_len = 0;

  double user_array[ MAX_SIZE ];

  FillArray( user_array, &array_len );

  double a_mean = arithMean( user_array, array_len );

  double g_mean = geomMean( user_array, array_len );

  double h_mean = harmonMean( user_array, array_len );

  printMeans(a_mean, g_mean, h_mean);

  return 0;

}
