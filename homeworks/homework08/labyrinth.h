#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdio.h>
#include <stdlib.h>

// NOTHING = 0
// SPELLBOOK = 1
// POTION = 2
// WAND = 3
// TREASURE = 4
typedef enum item {
    NOTHING, SPELLBOOK, POTION, WAND, TREASURE
}item;

/**********
* maze maze_cell
**********/
typedef struct maze_cell {

    // Pointers to the left, middle, and right
    // as well as the previous cell
    struct maze_cell* left;
    struct maze_cell* middle;
    struct maze_cell* right;
    struct maze_cell* previous;

    /* The unique ID for the cell */
    int unique_id;

    /* Establish the enumerated type value */
    enum item whats_here;

    /* The char used to generate the maze_cell */
    char generate_char;

}maze_cell;

/**********
* maze struct
* Contains a pointer to the initial cell in the Maze
**********/
typedef struct maze{

    struct maze_cell* start_cell;

}maze;

/***************************
 * Function Name: maze_constructor
 * Pre-Conditions: none
 * Post-Conditions: maze*
 *
 * dynamically allocates a maze* pointer, sets the start cell
 * to NULL, and then returns the point
 **************************/
maze* maze_constructor();

/***************************
 * Function Name: mc_constructor
 * Pre-Conditions: char generate_char
 * Post-Conditions: maze_cell*
 *
 * Dynamically allocates a maze_cell*, and used the curr_id and
 * generate_char to update specific information about the cell,
 * and then returns the maze_cell*
 **************************/
maze_cell* mc_constructor(maze_cell* previous, int curr_id, char generate_char);

/***************************
 * Function Name: which_item
 * Pre-Conditions: char generate_char
 * Post-Conditions: item
 *
 * Returns the specific item for the maze_cell based
 * upon a character.
 **************************/
item which_item( char generate_char );

#endif