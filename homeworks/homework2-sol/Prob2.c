/********************************
 * File Name: Prob2.c
 * Student's Name: Emily Govea
 * Student's Notre Dame NetID: egovea3
 * Date Started: 09/14/2023
 *******************************/

/* Finding Sum of a Range of Integers */
#include <stdio.h> 
/***************************
 * Function Name: find_sum
 * Pre-Conditions: int start, int end
 * Post-Conditions: int
 *
 * Returns the sum of a range of integers.
 **************************/
int find_sum( int start, int end );
/***************************
 * Function Name: print_sum
 * Pre-Conditions: int sum
 * Post-Conditions: int
 *
 * Returns the printed sum value of a range of integers.
 **************************/
void print_sum( int sum );

/* Main Function */
int main( void ){
    /* Variable Definitions */
    int int_start1 = 0, int_end1 = 100;
    int int_start2 = 22, int_end2 = 83;

    print_sum( find_sum(int_start1, int_end1) );
    print_sum( find_sum(int_start2, int_end2) );

    return 0;
}

/* Function Definitions */

/* This Function finds the sum of the integers using an if statement*/
int find_sum( int start, int end ){
    if( start > end ){
        return 0;
    }
    return start + find_sum(start + 1, end);
}
/* This function prints the sum value */
void print_sum( int sum ){
    fprintf( stdout, "Sum: %d\n", sum );
}