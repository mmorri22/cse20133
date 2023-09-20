/* Finding the current flowing through an RC Circuit */
#include <stdio.h>
#include <math.h> 

/* Function Declarations */
/***************************
 * Function Name: find_current
 * Pre-Conditions:double voltage, double resistor, double capacitor, double time, double Eul
 * Post-Conditions: double
 *
 * Returns the current flowing through an RC circuit. 
 **************************/
double find_current( double voltage, double resistor, double capacitor, double time, double Eul ); 

/***************************
 * Function Name: print_current
 * Pre-Conditions: double voltage, double resistor, double capacitor, double time, double Eul, double current
 * Post-Conditions: double
 *
 * Returns the printed current value flowing through an RC circuit. 
 **************************/
void print_current( double current ); 

/* Main Function */
int main( void ){
    /* Defined Variables */
    double E1 = 20, R1 = 10, C1 = 0.00440, t1 = 0.02300, e1 = 2.71838;
    double E2 = 35, R2 = 10, C2 = 0.016, t2 = 0.067, e2 = 2.71838;

    print_current( find_current(E1, R1, C1, t1, e1 ) );
    print_current( find_current(E2, R2, C2, t2, e2 ) );

    return 0;
}

/* This function calculates the current. */
double find_current( double voltage, double resistor, double capacitor, double time, double Eul ){
    return (voltage/resistor)*pow( Eul, -time/(resistor*capacitor));

}

/* This function prints the current value. */
void print_current( double current ){
    fprintf( stdout, "Voltage: %.5lf\n", current);
}