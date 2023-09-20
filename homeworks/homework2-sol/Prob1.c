 /* Finding Volume of a Sphere: V = 4/3 * pi * r^3 */
#include <stdio.h>

/* Function Declarations*/
/***************************
 * Function Name: vol_of_spheres
 * Pre-Conditions: double radius, double pi
 * Post-Conditions: double
 *
 * Returns the volume of the sphere.
 **************************/
double vol_of_sphere( double radius, double pi);

/***************************
 * Function Name: print_vol
 * Pre-Conditions: double radius, double pi, double volume
 * Post-Conditions: void
 *
 * Returns the printed volume of the sphere.
 **************************/
void print_vol( double volume );

/* Main Function */
int main( void ){
/* Defining My Variables */
  double r1 = 2, PI = 3.14159265;
  double r2 = 1.67;

  print_vol( vol_of_sphere( r1, PI ) );
  print_vol( vol_of_sphere( r2, PI ) );
  
  return 0;
}

/* Function Definitions */

/* This function calculates the volume of the sphere. */
double vol_of_sphere( double radius, double pi ){
  return (4/3.0) * pi * (radius*radius*radius);
}

/* This function prints the calculated volume. */
void print_vol( double volume ){
  fprintf( stdout, "Volume: %lf\n", volume);
}