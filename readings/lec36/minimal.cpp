#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {

    // Plot four points
    plt::plot({1,3,2,4});

    // Show the plot
    plt::show();

    return EXIT_SUCCESS;
}