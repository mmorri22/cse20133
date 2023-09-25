/*****************************
name: Answer Key
email: akey@nd.edu
file: function declarations
*****************************/

#include "means.h"

void FillArray( double user_array[], unsigned int* num_items ){

  /* print instructions message */
  fprintf( stdout, "please enter the values into the array\n" );

  /* fill array using a while loop */
  while( *num_items < NMAX ){

    fprintf( stdout, "enter a positive double (or -1 to end): " );
    fscanf( stdin, "%lf", &user_array[ iter ] );

    /* check to see if user terminated program */
    if( user_array[ *num_items ] < 0){
      return;
    }

    /* continue asking for entries if user has not terminated */
    *num_items += *num_items;

  }
}




double arithMean( double user_array[], unsigned int array_length ){
  /* initialize iterater and sum variables */
  unsigned int iter;
  double arithSum = 0;

  /* calculate sum of array using for loop */
  for( iter = 0; iter < array_length; iter++ ){
    arithSum = arithSum + user_array[ iter ];
  }

  /* calculate arithmetic mean */
  double aMean = arithSum / (double) array_length;

  return aMean;

}



double geomMean( double user_array[], unsigned int array_length ){
  /* initialize iterater and product variables */
  unsigned int iter;
  double geomProduct = 1;
  double exponent = (double) 1 / array_length;

  /* calculate product of array entries using for loop */
  for( iter = 0; iter < array_length; iter++ ){
    geomProduct = geomProduct * user_array[ iter ];
  }

  /* calculate geometric mean */
  double gMean = pow( geomProduct, exponent);

  return gMean;

}



double harmonMean( double user_array[], unsigned int array_length ){
  /* initialize iterator and summing variables */
  unsigned int iter;
  double inverseSum = 0;
  double user_array_inverse;
  double inverseSumAvg;

  /* calculate inverse sum of array entries using loop */
  for (iter = 0; iter < array_length; iter++ ){
    user_array_inverse = 1 / user_array[ iter ];
    inverseSum = inverseSum + user_array_inverse;
  }

  /* calculate average of inverse sum */
  inverseSumAvg = inverseSum / array_length;

  /* calculate harmonic mean */
  double hMean = 1 / inverseSumAvg;

  return hMean;

}


void printMeans(double arithMean, double geomMean, double harmonMean ){
  /* print the calculated means */
  fprintf( stdout, "arithmetic mean: %.6lf\n", arithMean );
  fprintf( stdout, "geometric mean: %.6lf\n", geomMean );
  fprintf( stdout, "harmonic mean: %.6lf\n", harmonMean );

}
