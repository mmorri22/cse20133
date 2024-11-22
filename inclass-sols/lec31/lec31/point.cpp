#include "point.h"

point::point() : x_coor(0), y_coor(0) {
    // Empty
}

point::point( const COORDINATE& x_in, const COORDINATE& y_in )
    : x_coor(x_in), y_coor(y_in)
{
    // Empty
}

COORDINATE point::get_x() const{
    return this->x_coor;
}

COORDINATE point::get_y() const{
    return this->y_coor;
}

void point::set_y( const COORDINATE& y_in ){
    this->y_coor = y_in;
}

void point::print() const{
    COUT << "{" << this->x_coor << ", " << this->y_coor << "}";
}