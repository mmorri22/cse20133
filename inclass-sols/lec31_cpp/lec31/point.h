#ifndef POINT_H
#define POINT_H

#include <iostream>

#define COORDINATE double
#define COUT std::cout
#define ENDL std::endl

class point{

    private:

        COORDINATE x_coor;
        COORDINATE y_coor;

    public:

        // Default Constructor
        point();

        // Overloaded Constructor
        point( const COORDINATE& x_in, const COORDINATE& y_in );

        COORDINATE get_x() const;

        COORDINATE get_y() const;

        void set_y( const COORDINATE& y_in );

        void print() const;

};


#endif