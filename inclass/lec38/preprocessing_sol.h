#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

class Iris {

    private: 
        float sepal_length; 
        float sepal_width;
        float petal_length;
        float petal_width;
        std::string ir_class;

    public:

        // Constructor
        Iris( const float& sepal_length, const float& sepal_width, 
            const float& petal_length, const float& petal_width, const std::string& ir_class ) :
            sepal_length(sepal_length), sepal_width(sepal_width), petal_length(petal_length),
            petal_width(petal_width), ir_class(ir_class) {}

        // Destructor
        ~Iris(){}

        float get_sepal_length() const{
            return this->sepal_length;
        }

        float get_sepal_width() const{
            return this->sepal_width;
        }

        float get_petal_length() const{
            return this->petal_length;
        }

        float get_petal_width() const{
            return this->petal_width;
        }

        void print_iris_data() const{

            std::cout << "------------------------------------------------------" << std::endl;
            std::cout << "Type: " << this->ir_class << std::endl;
            std::cout << "Sepal Length and Width: " <<  this->sepal_length << ", " << sepal_width << std::endl;
            std::cout << "Petal Length and Width: " <<  this->petal_length << ", " << petal_width << std::endl;

        }
}; 

std::vector< Iris > read_iris_dataset( const std::string& file_name );

void print_iris_dataset(const std::vector< Iris >& iris_dataset);

#endif