#include "preprocessing.h"

/* Iris Class Methods */

void Iris::print_iris_data() const{

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Type: " << this->ir_class << std::endl;
    std::cout << "Sepal Length and Width: " <<  this->sepal_length << ", " << sepal_width << std::endl;
    std::cout << "Petal Length and Width: " <<  this->petal_length << ", " << petal_width << std::endl;

}

std::vector< Iris > read_iris_dataset( const std::string& file_name ){

    /* Create the input stream from iris.data */
    std::ifstream myfile( file_name );
    
    /* We will eventuall store all these a vector of iris's called iris_dataset */
    std::vector< Iris > iris_dataset;

    /* Now we will create intermediate values to read in from the file */
    float sepal_len, sepal_wid, petal_len, petal_wid;
    std::string type_string;
    
    /* Check that the file exists! */
    if ( myfile.is_open() ){
    
        std::cout<< "Iris Dataset opened successfully" <<std::endl;

        /* Get the next line from */
        while (myfile >> sepal_len >> sepal_wid >> petal_len >> petal_wid >> type_string) {
        
            /* Construct an Iris */
            Iris temp_iris( sepal_len, sepal_wid, petal_len, petal_wid, type_string );
            
            /* Push it back onto the vector */
            iris_dataset.push_back( temp_iris );

        }

    }
    
    else{
        std::cout << "Unable to open file" << std::endl;
    }
    
    return iris_dataset;
}


void print_iris_dataset(const std::vector< Iris >& iris_dataset){

    // Iterate through the entire data set
    for( long unsigned int iter = 0; iter < iris_dataset.size(); ++iter ){

        // Print that Iris
        iris_dataset.at(iter).print_iris_data();
    }

}