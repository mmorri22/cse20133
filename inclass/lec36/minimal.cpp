#include <cmath>
#include <matplot/matplot.h>

using namespace matplot;

int main() {

    // Plot four points
    plot({1,3,2,4});

    // Set the Title
    title("Minimal Example");

    // Show the plot
    show();

    return EXIT_SUCCESS;
}