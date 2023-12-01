#include <cmath>
#include <matplot/matplot.h>
#include "preprocessing.h"

using namespace matplot;

int main(){

    std::vector< Iris > iris_dataset = read_iris_dataset( "iris.data" );

    print_iris_dataset( iris_dataset );

    // Create vectors of each data element


    // Pass the vectors to the plots

    return EXIT_SUCCESS;

}