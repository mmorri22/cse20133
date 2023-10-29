#include "preprocessing.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(){

    std::vector< Iris > iris_dataset = read_iris_dataset( "iris.data" );

    print_iris_dataset( iris_dataset );

    // Create vectors of each data element
    std::vector<float> sepal_len_vec;
    std::vector<float> sepal_wid_vec;
    std::vector<float> petal_len_vec;
    std::vector<float> petal_wid_vec;

    for( long unsigned int iter = 0; iter < iris_dataset.size(); ++iter ){

        sepal_len_vec.push_back( iris_dataset.at(iter).get_sepal_length() );
        sepal_wid_vec.push_back( iris_dataset.at(iter).get_sepal_width() );
        petal_len_vec.push_back( iris_dataset.at(iter).get_petal_length() );
        petal_wid_vec.push_back( iris_dataset.at(iter).get_petal_width() );

    }

    // Pass the vectors to the plots
    plt::plot( sepal_len_vec, {{"label", "sepal_length"}} );
    plt::plot( sepal_wid_vec, {{"label", "sepal_width"}} );
    plt::plot( petal_len_vec, {{"label", "petal_length"}} );
    plt::plot( petal_wid_vec, {{"label", "petal_width"}} );
    plt::title( "Standard usage" );
    plt::legend();
    plt::show();

    return EXIT_SUCCESS;

}