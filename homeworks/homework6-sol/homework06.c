#include "maze_generator.h"
#include "labrynth.h"

int main( const int argc, const char* argv[] ){

    if( argc != 2 ){
        fprintf( stderr, "Need two inputs\n" );
        return EXIT_FAILURE;
    }

    int curr_id = 1;
    int loc = 0;

    /* Create the initial cell in the Maze */
    maze_cell* start_cell = constructor( NULL, curr_id, argv[1][loc] );

    while( argv[1][loc] != '\0' ){

        maze_generate( start_cell, argv[1], &curr_id, &loc );

    }

    /* Print the maze */
    print_maze( start_cell );

    /* Delete the Maze to Free Memory */
    delete_maze( start_cell );

    return EXIT_SUCCESS;
}