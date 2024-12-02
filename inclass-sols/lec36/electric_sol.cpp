#include <matplot/matplot.h>
#include <cstdlib>
#include <iostream>

using namespace matplot;

int main() {

    // Represent the initial location
    double x_init = 1;
    double y_init = 1;
    double z_init = 4;

    // Set the variables
    double Q = 1*pow(10,-9);
    double C = 9*pow(10,9);

    // Part 1 - Create the x, y, and z using linspace 
    std::vector<double> x_range = linspace(0,2,10);
    std::vector<double> y_range = linspace(0,2,10);
    std::vector<double> z_range = linspace(3,5,10);

    // Part 1 - Initialize the Electric X, Y, and Z
    std::vector<double> x_coor;
    std::vector<double> y_coor;
    std::vector<double> z_coor;
    std::vector<double> electric_x;
    std::vector<double> electric_y;
    std::vector<double> electric_z;

    for( size_t iter = 0; iter < x_range.size(); ++iter ){

        for( size_t jter = 0; jter < y_range.size(); ++jter ){

            for( size_t kter = 0; kter < z_range.size(); ++kter ){

                /* Part 2 */
                /* Copy the current value from the array to local copies */
                double x_curr = x_range.at(iter);
                double y_curr = y_range.at(jter);
                double z_curr = z_range.at(kter);

                /* Push these local values on the back of corr vectors */
                x_coor.push_back(x_curr);
                y_coor.push_back(y_curr);
                z_coor.push_back(z_curr);

                /* Calculate the diff we will need for the vector */
                double x_diff = x_curr - x_init;
                double y_diff = y_curr - y_init;
                double z_diff = z_curr - z_init;

                /* We will next use pow to calculate the unit vector */
                double unit_vec = pow(( pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2)), 0.5);
                
                /* Calculate the Ex, Ey, and Ez */
                double electric_x_curr = Q*C*unit_vec/pow(x_diff,2);
                double electric_y_curr = Q*C*unit_vec/pow(y_diff,2);
                double electric_z_curr = Q*C*unit_vec/pow(z_diff,2);

                electric_x.push_back(electric_x_curr);
                electric_y.push_back(electric_y_curr);
                electric_z.push_back(electric_z_curr);
                
            }
        }
    }

    /* Part 3 */
    quiver3(x_coor, y_coor, z_coor, electric_x, electric_y, electric_z);

    show();
    
    return EXIT_SUCCESS;

}