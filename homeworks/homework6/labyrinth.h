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

typedef struct maze_cell {

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

maze_cell* constructor(maze_cell* previous, int curr_id, char generate_char);

item which_item( char generate_char );

#endif