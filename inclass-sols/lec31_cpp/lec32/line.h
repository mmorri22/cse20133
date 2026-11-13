#ifndef LINE_H
#define LINE_H 

#include "point.h"

typedef double SLOPE;

class line{

    private:

        point origin;
        point destin;

    public:

        // Default Constructor
        line();

        line( const point& origin_in, const point& destin_in );

        line( const COORDINATE& origin_in_x, const COORDINATE& origin_in_y, 
            const COORDINATE& destin_in_x, const COORDINATE& destin_in_y);

        point getOrigin() const;

        point getDestin() const;

        SLOPE getSlope() const;

        void print() const;

};

#endif