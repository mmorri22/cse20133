#ifndef LINE_H
#define LINE_H 

#include "point.h"

typedef double SLOPE;

class line{
	
	private:
		point origin;
		point destin;
	
	public:
	
		line();
		
		line(point originIn, point destinIn);
		
		point getOrigin() const;
		
		point getDestin() const;
		
		SLOPE getSlope() const;
	
		void print() const;	

};

#endif