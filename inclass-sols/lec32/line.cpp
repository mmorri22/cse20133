#include "line.h"

line::line() : origin( point() ), destin( point(0, 0) ) {}

line::line( const point& origin_in, const point& destin_in )
    : origin( origin_in ), destin( destin_in ) {}


line::line( const COORDINATE& x_1, const COORDINATE& y_1, 
    const COORDINATE& x_2, const COORDINATE& y_2 )
    : origin( point(x_1, y_1) ), destin( point(x_2, y_2) ) {} 


point line::getOrigin() const{
    return this->origin;
}


point line::getDestin() const{
    return this->destin;
}


SLOPE line::getSlope() const{

    return (this->destin.get_y() - this->origin.get_y()) / (destin.get_x() - origin.get_x()) ;

}


void line::print() const{

    COUT << "{";

    this->origin.print();

    COUT << ",";

    this->destin.print();

    COUT << "}";
}