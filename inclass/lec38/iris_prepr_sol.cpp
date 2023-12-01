#include "preprocessing.h"

int main(){

    std::vector< Iris > iris_dataset = read_iris_dataset( "iris.data" );

    print_iris_dataset( iris_dataset );

    return EXIT_SUCCESS;

}