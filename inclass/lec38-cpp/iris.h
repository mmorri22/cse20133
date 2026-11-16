#ifndef IRIS_H
#define IRIS_H

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

        // Write the Constructor
        Iris( const float& sepal_length, const float& sepal_width, 
            const float& petal_length, const float& petal_width, const std::string& ir_class );

        // Destructor
        ~Iris(){}

        // Write the get_sepal_length
        float get_sepal_length() const;

        // Write the get_sepal_length
        float get_sepal_width() const;

        // Write the get_petal_length
        float get_petal_length() const;

        // Write the get_petal_length
        float get_petal_width() const;

        // print iris data
        void print_iris_data() const;
}; 

#endif