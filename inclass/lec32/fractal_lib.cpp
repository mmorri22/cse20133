#include "fractal_lib.h"

void sierpinski( double x1, double y1, double x2, double y2, double x3, double y3 )
{
   // Base case. 
   

   // Draw the triangle
   

   // Recursive calls
   
}

void shrinkingSquares( double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4 ){
	double fourth = .25*(x2-x1); // finds 25% percent of side
   // Base case. 
   if( abs(x2-x1) < 5 ) return;

   // Draw the triangle
   drawSquare(x1,y1,x2,y2,x3,y3,x4,y4);

   // Recursive calls
   shrinkingSquares(x1-fourth, y1-fourth, x1+fourth, y1-fourth, x1-fourth, y1+fourth, x1+fourth, y1+fourth);
   shrinkingSquares(x2-fourth, y2-fourth, x2+fourth, y2-fourth, x2-fourth, y2+fourth, x2+fourth, y2+fourth);
   shrinkingSquares(x3-fourth, y3-fourth, x3+fourth, y3-fourth, x3-fourth, y3+fourth, x3+fourth, y3+fourth);
   shrinkingSquares(x4-fourth, y4-fourth, x4+fourth, y4-fourth, x4-fourth, y4+fourth, x4+fourth, y4+fourth);
}

void spiralSquares(double x0,double y0, double r, double angle){
	
	// Base Case

	// New Coordinates
	

	// Set the new angle
	

	// Derive the offset
	
	// Draw a square
	

	// Set the new radius as 0.92 of the old radius and call spiralSquares
	
	

}

void circularLace(double x0, double y0, double r) {
	if(r < 2) return;

	gfx_circle(x0,y0,r);

	for(double i = 0; i <= 360; i=i+60){
		double x = x0 + (r * sin(i * (M_PI / 180)));
		double y = y0 - (r * cos(i * (M_PI / 180)));

		gfx_circle(x,y, r/3);
		circularLace(x,y,r/3);
	}
}

void snowflake(double x0, double y0, double len){
	if(len < 1) return;

	gfx_poly(5,x0,y0,len);

	//finds five podoubles of pentagon

	double angle = (360 / (2 * 5));  
	double p1_X = x0 + (len * sin(angle * (M_PI / 180)));
	double p1_Y = y0 - (len * cos(angle * (M_PI / 180)));

	angle = angle - (360/5);

	double p2_X = x0 +(len * sin(angle * (M_PI / 180)));
	double p2_Y = y0 - (len * cos(angle * (M_PI / 180)));

	angle = angle - (360/5);

	double p3_X = x0 + (len * sin(angle * (M_PI / 180)));
	double p3_Y = y0 - (len * cos(angle * (M_PI / 180)));

	angle = angle - (360/5);

	double p4_X = x0 +(len * sin(angle * (M_PI / 180)));
	double p4_Y = y0 - (len * cos(angle * (M_PI / 180)));

	angle = angle - (360/5);

	double p5_X = x0 + (len * sin(angle * (M_PI / 180)));
	double p5_Y = y0 - (len * cos(angle * (M_PI / 180)));

	snowflake(p1_X, p1_Y, len/3);
	snowflake(p2_X, p2_Y, len/3);
	snowflake(p3_X, p3_Y, len/3);
	snowflake(p4_X, p4_Y, len/3);
	snowflake(p5_X, p5_Y, len/3);

}

void tree(double x0, double y0, double len, double angle) {
	if(len < 2) return;

	double x1 = x0 + (len * sin(angle * (M_PI / 180)));	// new coordinates
	double y1 = y0 - (len * cos(angle * (M_PI / 180)));

	double angle1 = angle - 30;

	double x2 = x0 + (len * sin(angle * (M_PI / 180)));
	double y2 = y0 - (len * cos(angle * (M_PI / 180)));

	double angle2 = angle + 30;

	double x3 = x0 + (len * sin(angle * (M_PI / 180)));
	double y3 = y0 - (len * cos(angle * (M_PI / 180)));

	gfx_line(x0,y0,x1,y1);
	gfx_line(x1,y1,x2,y2);
	gfx_line(x1,y1,x3,y3);

	double nLen = len*(.75);

	tree(x2,y2,nLen, angle1);
	tree(x3,y3,nLen, angle2);

}

void fern(double x0,double y0, double len, double angle){
	if(len < 5) return;


	double x1 = x0 + (len * sin(angle * (M_PI / 180)));	//top
	double y1 = y0 - (len * cos(angle * (M_PI / 180)));

	double x2 = x0 + ((.75)*len * sin(angle * (M_PI / 180)));	///next from top
	double y2 = y0 - ((.75)*len * cos(angle * (M_PI / 180)));

	double x3 = x0 + ((.5)*len * sin(angle * (M_PI / 180)));	
	double y3 = y0 - ((.5)*len * cos(angle * (M_PI / 180)));

	double x4 = x0 + ((.25)*len * sin(angle * (M_PI / 180)));	
	double y4 = y0 - ((.25)*len * cos(angle * (M_PI / 180)));

	len = len/3;

	double angle1 = angle + 30;	

	double x1_A = x1 + (len * sin(angle1 * (M_PI / 180)));	//top
	double y1_A = y1 - (len * cos(angle1 * (M_PI / 180)));

	double x2_A = x2 + (len * sin(angle1 * (M_PI / 180)));	///next from top
	double y2_A = y2 - (len * cos(angle1 * (M_PI / 180)));

	double x3_A = x3 + (len * sin(angle1 * (M_PI / 180)));	
	double y3_A = y3 - (len * cos(angle1 * (M_PI / 180)));

	double x4_A = x4 + (len * sin(angle1 * (M_PI / 180)));	
	double y4_A = y4 - (len * cos(angle1 * (M_PI / 180)));

	double angle2 = angle - 30;	

	double x1_B = x1 + (len * sin(angle2 * (M_PI / 180)));	//top
	double y1_B = y1 - (len * cos(angle2 * (M_PI / 180)));

	double x2_B = x2 + (len * sin(angle2 * (M_PI / 180)));	///next from top
	double y2_B = y2 - (len * cos(angle2 * (M_PI / 180)));

	double x3_B = x3 + (len * sin(angle2 * (M_PI / 180)));	
	double y3_B = y3 - (len * cos(angle2 * (M_PI / 180)));

	double x4_B = x4 + (len * sin(angle2 * (M_PI / 180)));	
	double y4_B = y4 - (len * cos(angle2 * (M_PI / 180)));
		

	gfx_line(x0,y0,x1,y1);
	gfx_line(x1,y1,x1_A,y1_A);
	gfx_line(x1,y1,x1_B,y1_B);

	gfx_line(x2,y2,x2_A,y2_A);
	gfx_line(x2,y2,x2_B,y2_B);

	gfx_line(x3,y3,x3_A,y3_A);
	gfx_line(x3,y3,x3_B,y3_B);

	gfx_line(x4,y4,x4_A,y4_A);
	gfx_line(x4,y4,x4_B,y4_B);

	fern(x1,y1, len, angle1);
	fern(x1,y1, len, angle2);

	fern(x2,y2, len, angle1);
	fern(x2,y2, len, angle2);

	fern(x3,y3, len, angle1);
	fern(x3,y3, len, angle2);

	fern(x4,y4, len, angle1);
	fern(x4,y4, len, angle2);

}

void spiral( double x0, double y0, double r, double angle){
   	if(r < 1) return;

	double x = x0 + (r * sin(angle * (M_PI / 180)));	// new coordinates
	double y = y0 - (r * cos(angle * (M_PI / 180)));

	double angle1 = angle + 30;

	gfx_point(x,y);

	double rNew = r*.90;
	double rNew2 = r*.4;
	spiral(x,y, rNew2, angle);
	spiral(x0,y0, rNew, angle1);
}

void drawSquare(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	gfx_line(x1,y1,x2,y2);
	gfx_line(x2,y2,x4,y4);
	gfx_line(x4,y4,x3,y3);
	gfx_line(x3,y3,x1,y1);
}

void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3){
	gfx_line(x1,y2,x2,y2);
	gfx_line(x2,y2,x3,y3);
	gfx_line(x3,y3,x1,y1);
}




void gfx_poly(double s, double x0, double y0, double len) {

	double angle = (360 / (2 * s));	// Angle of doubleerior angles / 2

	for (double k = 0; k <= s; k++) {
		double x1 = x0 + (len * sin(angle * (M_PI / 180)));
		double y1 = y0 - (len * cos(angle * (M_PI / 180)));
		gfx_line(x0, y0, (int)x1, (int)y1);
		angle = angle - (360 / s);	// Rotate 
	}

}
