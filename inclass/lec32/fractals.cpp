//Rad + Raellene

#include "fractal_lib.h"

int main( const int argc, const char* argv[] ){

	if( argc != 3 ){
		std::cout << "Need 3 inputs" << std::endl;
		return EXIT_FAILURE;
	}

	unsigned int width = (unsigned int)atoi(argv[1]);
	unsigned int height = (unsigned int)atoi(argv[2]);

	gfx_open (width, height, "CSE 20133 Fractals");
	bool quit = false;
	size_t user_case;

	
	while(!quit) {
  		user_case = gfx_wait();      // wait for the first mouse click

 		switch(user_case) {
 			case '1':
 				gfx_flush();	// Sierpinski
 				gfx_clear();
				sierpinski(50,50,450,50,250,350);
 				sierpinski(50,50,(double)width-50,50,(double)width/2,(double)height-50);
 				break;
 			case '2':
 				gfx_flush();	// Shrinking Squares
 				gfx_clear();
 				shrinkingSquares(0,0,(double)height,0,0,(double)width,(double)height,(double)width);
 				break;
 			case '3':
 				gfx_flush();	// Spiral Squarea
 				gfx_clear();
				
 				spiralSquares((double)height/2,(double)width/2, (double)height/2, (double)width/2);
 				break;
 			case '4':
 				gfx_flush();	// Circular Lace
 				gfx_clear();
 				circularLace((double)height/2,(double)width/2, (double)height/4);
 				break;
 			case '5':
 				gfx_flush();	// Snowflake
 				gfx_clear();
 				snowflake((double)height/2,(double)width/2, (double)height/4);
 				break;
 			case '6':
 				gfx_flush();	// Tree
 				gfx_clear();
 				tree((double)height/2,(double)width,(double)width/5, 0);
 				break;
 			case '7':
 				gfx_flush();	// Fern
 				gfx_clear();
 				fern((double)height/2, (double)width, (double)width/1.5, 0); 				
 				break;
 			case '8':
 				gfx_flush();	// Spiral
 				gfx_clear();
 				spiral((double)height/2, (double)height/2, (double)width/1.5, 180); 			
 				break;

 			case 'q':
			 	gfx_flush();	// Spiral
 				gfx_clear();
 				quit = true;
 				break;

 		}
 	}

}