
/* Finding the Minimum Radius of a Cylindrical Rod */
#include <stdio.h>
#include <math.h> 

/* Function Declarations */
/***************************
 * Function Name: min_radius
 * Pre-Conditions: double diameter, double weight, double stress
 * Post-Conditions: double
 *
 * Returns the radius of a cylndrical rod. 
 **************************/
double min_radius( double diameter, double weight, double pi, double stress );
/***************************
 * Function Name: print_radius
 * Pre-Conditions: double diameter, double weight, double stress, double radius
 * Post-Conditions: double
 *
 * Returns the printed radius value of a cylndrical rod. 
 **************************/
void print_radius( double radius );

/* Main Function */
int main( void ){

/* Defining the Variables I Will Use in the Equation */
    double d1 = 7.00, P1 = 300.00, PI = 3.14159265, s1 = 10000.00;
    double d2 = 5.00, P2 = 150.00, s2 = 7000.00;

    print_radius( min_radius(d1, P1, PI, s1) );
    print_radius( min_radius(d2, P2, PI, s2) );

    return 0;
}

/* Function Definitions */

/* This function will calculate the radius.*/
double min_radius( double diameter, double weight, double pi, double stress ){
    return pow(((diameter*weight)/(pi*stress)), 0.333333);

}

/* This function prints the calculated radius. */
void print_radius( double radius ){
    fprintf( stdout, "Minimum Radius: %lf\n", radius );
}