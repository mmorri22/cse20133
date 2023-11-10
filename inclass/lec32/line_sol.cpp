#include "line.h"

line::line() : origin( point(0, 0) ), destin( point(0, 0) ) {}

line::line(point originIn, point destinIn) : origin(originIn), destin(destinIn) {}
	
	
point line::getOrigin() const{
	
	return origin;
}

point line::getDestin() const{
	
	return destin;
}


SLOPE line::getSlope() const{
	
	return (destin.get_y() - origin.get_y()) / (destin.get_x() - origin.get_x());
	
}

void line::print() const{

	COUT << "{";

	this->origin.print();

	COUT << ", ";

	this->destin.print();

	COUT << "}";
	
}