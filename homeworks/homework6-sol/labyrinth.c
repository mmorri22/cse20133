#include "labyrinth.h"

maze_cell* constructor(maze_cell* previous, int curr_id, char generate_char){

    maze_cell* new_cell = (maze_cell*)malloc( sizeof(maze_cell) );
    new_cell->unique_id = curr_id;
    new_cell->generate_char = generate_char;
    new_cell->whats_here = which_item( generate_char );

    new_cell->left = NULL;
    new_cell->right = NULL;
    new_cell->middle = NULL;
    new_cell->previous = previous;

    return new_cell;

}

item which_item( char generate_char ){

    int result = generate_char % 6;

    if( result == 2 ){
        return SPELLBOOK;
    }

    else if( result == 4 ){
        return POTION;
    }

    else if( result == 5 ){
        return WAND;
    }

    else
        return NOTHING;

}