#include "iris.h"

Iris::Iris( const float& sepal_length, const float& sepal_width, 
    const float& petal_length, const float& petal_width, const std::string& ir_class ) :
    sepal_length(sepal_length), sepal_width(sepal_width), petal_length(petal_length),
    petal_width(petal_width), ir_class(ir_class) {}

float Iris::get_sepal_length() const{
    return this->sepal_length;
}

float Iris::get_sepal_width() const{
    return this->sepal_width;
}

float Iris::get_petal_length() const{
    return this->petal_length;
}

float Iris::get_petal_width() const{
    return this->petal_width;
}

/* Iris Class Methods */
void Iris::print_iris_data() const{

    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Type: " << this->ir_class << std::endl;
    std::cout << "Sepal Length and Width: " <<  this->sepal_length << ", " << sepal_width << std::endl;
    std::cout << "Petal Length and Width: " <<  this->petal_length << ", " << petal_width << std::endl;

}