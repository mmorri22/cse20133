#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include "labyrinth.h"

// Compiler directives for going in directions
#define LEFT 0
#define MIDDLE 1
#define RIGHT 2
#define GO_BACK 3

/***************************
 * Function Name: generate_maze
 * Pre-Conditions: maze* the_maze, const char* key_string
 * Post-Conditions: void
 *
 * Takes in the maze pointer and generates the entire maze
 * using a recursively called generate_cell
 **************************/
void generate_maze( maze* the_maze, const char* key_string );

/***************************
 * Function Name: generate_maze
 * Pre-Conditions: maze_cell* curr_cell, const char* key_string, int* curr_id, int* char_loc
 * Post-Conditions: void
 *
 * Either generates a new cell or traverses previous cells based on the directions
 * The curr_id is used to uniquely identify a newly generated cell
 * char_loc is used to keep track of which char in key_string we are referring to
 **************************/
void generate_cell(maze_cell* curr_cell, const char* key_string, int* curr_id, int* char_loc);

/***************************
 * Function Name: print_maze
 * Pre-Conditions: maze_cell* curr_cell
 * Post-Conditions: void
 *
 * Uses a depth-first search to print the maze
 * Goes left, middle, and then right
 **************************/
void print_maze( maze_cell* curr_cell );

/***************************
 * Function Name: delete_maze
 * Pre-Conditions: maze_cell* curr_cell
 * Post-Conditions: void
 *
 * Uses a depth-first search to delete the maze_cells
 * Goes left, middle, and then right
 **************************/
void delete_maze(maze_cell* curr_cell);

#endif