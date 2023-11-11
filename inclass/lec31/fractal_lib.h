#ifndef FRACTAL_LIB_H
#define FRACTAL_LIB_H

#include <unistd.h>
#include <cstdlib>
#include <math.h>
#include "gfx.h"

void sierpinski(double,double,double,double,double, double);
void drawTriangle(double,double,double,double,double,double);
void shrinkingSquares(double,double,double,double,double,double,double,double);
void drawSquare(double,double,double,double,double,double,double,double);
void gfx_poly(double, double, double, double);
void snowflake(double,double,double);
void tree(double,double,double, double);
void spiralSquares(double,double, double, double);
void circularLace(double, double, double);
void fern(double,double,double,double);
void spiral( double, double, double, double);

#endif