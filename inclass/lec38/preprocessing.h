#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

/* Iris Class */
        


std::vector< Iris > read_iris_dataset( const std::string& file_name );

void print_iris_dataset(const std::vector< Iris >& iris_dataset);

#endif