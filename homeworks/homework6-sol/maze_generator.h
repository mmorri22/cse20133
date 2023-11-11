#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include "labrynth.h"

#define LEFT 0
#define MIDDLE 1
#define RIGHT 2
#define GO_BACK 3

void maze_generate(maze_cell* curr_cell, const char* name, int* curr_id, int* char_loc);

void print_maze( maze_cell* curr_cell );

void delete_maze(maze_cell* curr_cell);

#endif