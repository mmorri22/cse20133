#include <stdio.h>
#include <math.h>

/* Function Declarations */
/***************************
 * Function Name: find_bacteria
 * Pre-Conditions: double initial, double Eul, double growth, double time
 * Post-Conditions: double
 *
 * Returns the bacteria in a culture subjected to refrigeration.
 **************************/
double find_bacteria( double initial, double Eul, double growth, double time );
/***************************
 * Function Name: print_bacteria
 * Pre-Conditions: double initial, double Eul, double growth, double time, double bacteria
 * Post-Conditions: double
 *
 * Returns the printed bacteria value in a culture subjected to refrigeration.
 **************************/
void print_bacteria(double bacteria );

/* Main Function */
int main( void ){
    /* Defining my variables. */
    double i1 = 300000, e1 = 2.71828, k1 = -0.032, t1 = 12;
    double i2 = 300000, e2 = 2.71828, k2 = -0.032, t2 = 18;

    print_bacteria( find_bacteria( i1, e1, k1, t1) );
    print_bacteria( find_bacteria( i2, e2, k2, t2) );
}

/* Function Definitions */

/* This Function calculates the value of bacteria. */
double find_bacteria( double initial, double Eul, double growth, double time){
    return initial*pow( Eul, growth*time);
}

/* This function prints the bacteria value. */
void print_bacteria( double bacteria ){
    fprintf( stdout, "Bacteria: %.5lf\n", bacteria );
}