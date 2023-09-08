#ifndef PARALLEL_LIB_H
#define PARALLEL_LIB_H

#include <stdio.h>
#include <math.h>

double add_resis( double R1, double R2, double R3 );

double invert( double R_sum );

void print( double R1, double R2, double R3, double R_sum );


#endif