#include <cmath>
#include <matplot/matplot.h>

int main() {

    using namespace matplot;

    // Plot four points
    plot({1,3,2,4});

    // Show the plot
    show();

    return EXIT_SUCCESS;
}