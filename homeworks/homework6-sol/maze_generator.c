#include "maze_generator.h"

void maze_generate(maze_cell* curr_cell, const char* name, int* curr_id, int* char_loc){

    // Increment the location by 1
    (*char_loc)++;

    // End if we've reached the end of the name
    if(name[*char_loc] == '\0'){

        curr_cell->whats_here = TREASURE;
        return;

    }

    if(name[*char_loc] == ' '){
        return;
    }

    // Use the char to do the 
    int next_direction = name[*char_loc] % 4;

    if( next_direction == GO_BACK ){

        // Go backwards by returning
        maze_generate( curr_cell->previous, name, curr_id, char_loc );
    }

    else if( next_direction == LEFT ){

        if(curr_cell->left == NULL){

            (*curr_id)++;

            curr_cell->left = constructor( curr_cell, *curr_id, name[*char_loc] );
        }

        maze_generate( curr_cell->left, name, curr_id, char_loc );

    }

    else if( next_direction == MIDDLE ){

        if(curr_cell->middle == NULL){

            (*curr_id)++;

            curr_cell->middle = constructor( curr_cell, *curr_id, name[*char_loc] );
        }

        maze_generate( curr_cell->middle, name, curr_id, char_loc );

    }

    else if( next_direction == RIGHT ){

        if(curr_cell->right == NULL){

            (*curr_id)++;

            curr_cell->right = constructor( curr_cell, *curr_id, name[*char_loc] );
        }

        maze_generate( curr_cell->right, name, curr_id, char_loc );

    }

}

void print_maze( maze_cell* curr_cell ){

    int curr_id = curr_cell->unique_id;

    fprintf( stdout, "ID: %d generated using %c\n", curr_id, curr_cell->generate_char );

    if( curr_cell->whats_here == NOTHING ){
        fprintf(stdout, "Nothing's here! let's keep looking\n");
    }
    else if(curr_cell->whats_here == SPELLBOOK){
        fprintf(stdout, "We found a Spellbook! Be careful what you chant...\n");
    }
    else if(curr_cell->whats_here == POTION){
        fprintf(stdout, "We found a Potion! Check to see what the potion before you drink it.\n");
    }
    else if(curr_cell->whats_here == WAND){
        fprintf(stdout, "We found a Wand! It's pronounced levio-SAH.\n");
    }
    else if(curr_cell->whats_here == TREASURE){
        fprintf(stdout, "We found the treasure! WE'RE RICH!\n");
    }

    if( curr_cell->left != NULL ){
        fprintf( stdout, "There is a path to the left in cell %d!\n", curr_id);
        print_maze( curr_cell->left );
    }

    if( curr_cell->middle != NULL ){
        fprintf( stdout, "There is a path in the middle in cell %d!\n", curr_id);
        print_maze( curr_cell->middle );
    }

    if( curr_cell->right != NULL ){
        fprintf( stdout, "There is a path to the right in cell %d!\n", curr_id);
        print_maze( curr_cell->right );
    }

    fprintf( stdout, "There are no more valid paths in %d! Going backwards.\n", curr_id);

}

void delete_maze(maze_cell* curr_cell){
    
    if( curr_cell->left != NULL )
        delete_maze( curr_cell->left );

    if( curr_cell->middle != NULL )
        delete_maze( curr_cell->middle );

    if( curr_cell->right != NULL )
        delete_maze( curr_cell->right );

    free( curr_cell );
}
