#include "point.h"

point::point() : x_coor(0), y_coor(0) {}


point::point( const COORDINATE& x_in, const COORDINATE& y_in )
	: x_coor(x_in), y_coor(y_in) {}
	

COORDINATE point::get_x() const{
	
	return x_coor;
}

COORDINATE point::get_y() const{
	
	return y_coor;
}

void point::print() const{
	
	COUT << "{" << x_coor << ", " << y_coor << "}";
}

void point::set_y( const COORDINATE& y_in ){
	
	y_coor = y_in;
}