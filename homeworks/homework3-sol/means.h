/*****************************
name: ethan elau
email: elau@nd.edu
file: function definitions
*****************************/

#ifndef MEANS_H
#define MEANS_H

#include <stdio.h>
#include <math.h>

#define MAX_SIZE 25


void FillArray( double user_array[], unsigned int* array_length );

double arithMean( double user_array[], unsigned int array_length);

double geomMean( double user_array[], unsigned int array_length );

double harmonMean( double user_array[], unsigned int array_length );

void printMeans(double arithMean, double geomMean, double harmonMean );


#endif
