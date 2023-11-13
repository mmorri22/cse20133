#ifndef LINE_H
#define LINE_H 

#include "point.h"

#define SLOPE double

class line{

    private:

        point origin;
        point destin;

    public:

        line();

        // origin_in, destin_in
        line( const point& origin_in, const point& destin_in );

        line( const COORDINATE& x_1, const COORDINATE& y_1, 
            const COORDINATE& x_2, const COORDINATE& y_2 );

        point getOrigin() const;

        point getDestin() const;

        SLOPE getSlope() const;

        void print() const;

};

#endif