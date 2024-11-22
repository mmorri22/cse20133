#include "point.h"

int main(){

	point point1;
	
	std::cout << "point1 is ";
	point1.print();
	std::cout << std::endl;
	
	/* Update values */
	point1.set_y( (COORDINATE)6.2 );
	
	std::cout << "After update: point1 is "; 
	point1.print();
	std::cout << std::endl;

	/* Second constructor for point */
	const point point2( (COORDINATE)-1.1, (COORDINATE)5.3 );
	
	std::cout << "point2 is ";
	point2.print();
	std::cout << std::endl << std::endl;	
	
	return 0;
}
