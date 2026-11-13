#include "line.h"

int main(){

	point point1;
	point1.set_y( (COORDINATE)6.2 );

	/* Second constructor for point */
	const point point2( (COORDINATE)-1.1, (COORDINATE)5.3 );
	
	
	/* Default constructor for line */
	line line1;
	std::cout << "line1 is ";
	line1.print();
	std::cout <<std::endl << std::endl;	
	
	/* Constructor qwith points for line */
	line line2(point1, point2);
	std::cout << "line2 is ";
	line2.print();
	std::cout <<std::endl << std::endl;	
	
	
	/* Print all slopes */
	std::cout << "line1 slope is " << line1.getSlope() << std::endl;
	std::cout << "line2 slope is " << line2.getSlope() << std::endl;
	
	return 0;
}
