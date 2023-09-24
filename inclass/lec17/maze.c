#include <stdio.h>

#define ROWS 11
#define COLS 11

void print_maze( char the_maze[ROWS][COLS] );

/* Write the recursive function declaration */

int main(){

  char the_maze[ROWS][COLS] = {
    { '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' },
    { '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|' },
    { '|', ' ', '-', '-', '-', '-', '-', '-', '-', ' ', '|' },
    { '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|' },
    { '|', ' ', ' ', ' ', '|', ' ', '|', ' ', '-', '-', '|' },
    { '|', '-', '-', ' ', '|', ' ', '|', ' ', ' ', ' ', '|' },
    { '|', ' ', ' ', ' ', '|', ' ', '|', '-', '-', ' ', '|' },
    { '|', ' ', '-', '-', '-', ' ', ' ', 'F', '|', ' ', '|' },
    { '|', ' ', '|', ' ', '|', '-', '-', '-', '-', ' ', '|' },
    { '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|' },
    { '|', '-', '-', '-', '-', '-', '-', '-', '-', '-', '|' }
  };

  /* Print the initial maze */
  print_maze( the_maze );

  /* Run the algorithm */
  int start_x = 1;
  int start_y = 1;

  /* Call the recursive function */


  if( found == 0 ){
    fprintf(stdout, "The maze was not solvable from (%d, %d)\n", start_x, start_y );
  }
  else{
    fprintf(stdout, "The maze was solved!\n");
    print_maze( the_maze );
  }

  return 0;
}

void print_maze( char the_maze[ROWS][COLS] ){

  int row_iter, col_iter;
  for(row_iter = 0; row_iter < ROWS; ++row_iter){

    for(col_iter = 0; col_iter < ROWS; ++col_iter){
      fprintf(stdout, " %c ", the_maze[row_iter][col_iter] );
    }
    fprintf( stdout, "\n" );
  }
  fprintf( stdout, "\n" );

}

/* Write the recursive function definition */
