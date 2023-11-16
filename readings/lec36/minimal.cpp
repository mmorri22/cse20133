#include <cmath>
#include <matplot/matplot.h>

int main() {

    // Plot four points
    matplot::plot({1,3,2,4});

    // Show the plot
    matplot::show();

    return EXIT_SUCCESS;
}