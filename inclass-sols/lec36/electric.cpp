#include <matplot/matplot.h>
#include <cstdlib>
#include <iostream>

using namespace matplot;

int main() {

    // Represent the initial location


    // Set the variables Q and C


    // Part 1 - Create the x, y, and z using linspace 


    // Part 1 - Initialize the Electric X, Y, and Z


    for( size_t iter = 0; iter < x_range.size(); ++iter ){

        for( size_t jter = 0; jter < y_range.size(); ++jter ){

            for( size_t kter = 0; kter < z_range.size(); ++kter ){

                /* Part 2 */
                /* Copy the current value from the array to local copies */


                /* Push these local values on the back of corr vectors */


                /* Calculate the diff we will need for the vector */


                /* We will next use pow to calculate the unit vector */
                
                /* Calculate the Ex, Ey, and Ez */
                
            }
        }
    }

    /* Part 3 */

    
    return EXIT_SUCCESS;

}