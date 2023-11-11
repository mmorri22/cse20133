// A simple graphics library for CSE 20311 
// Originally created by Prof. Doug Thain
// Modified and augmented by Prof. Ramzi Bualuan
// Modified and augmented by Prof. Matthew Morrison
// Last edit: Nov 26, 2016

#ifndef GFX_H
#define GFX_H

#include <X11/Xlib.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

// Open a new graphics window. 
void gfx_open( unsigned int width, unsigned int height, const char *title );

// Flush all previous output to the window. 
void gfx_flush();

// Change the current drawing color. 
void gfx_color( int r, int g, int b );

// Clear the graphics window to the background color. 
void gfx_clear();

// Change the current background color. 
void gfx_clear_color( int r, int g, int b );

// Check to see if an event is waiting. 
double gfx_event_waiting();

// Wait for the user to press a key or mouse button. 
size_t gfx_wait();

// Return the X and Y coordinates of the last event. 
double gfx_xpos();
double gfx_ypos();

// Return the X and Y dimensions of the screen (monitor). 
double gfx_xsize();
double gfx_ysize();

// Draw a podouble at (x,y) 
void gfx_point( double x, double y );

// Draw a line from (x1,y1) to (x2,y2) 
void gfx_line( double x1, double y1, double x2, double y2 );

// Draw a circle centered at (xc,yc) with radius r 
void gfx_circle( double xc, double yc, double r );

// Display a string at (x,y) 
void gfx_text( double x, double y , const char *text );

#endif

