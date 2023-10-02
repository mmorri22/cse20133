#include <stdio.h>

#define ROWS 11
#define COLS 11

void print_maze( char the_maze[ROWS][COLS] );

/* Write the recursive function declaration */
int depth_first_search( char the_maze[ROWS][COLS], int curr_row, int curr_col );

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
  int found = depth_first_search( the_maze, start_x, start_y );

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

  sleep( 1 );
  if( system("clear") ){}
  
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
int depth_first_search( char the_maze[ROWS][COLS], int curr_row, int curr_col ){

  // Base Case
  if( the_maze[curr_row][curr_col] == 'F'){

    fprintf(stdout, "Solved!\n" );
    return 1;
  }

  the_maze[curr_row][curr_col] = 'X';
  print_maze( the_maze );

  int check=0;

  // Check Left
  if( check == 0 && curr_col-1 >= 0 && ( the_maze[curr_row][curr_col-1] == ' '
    || the_maze[curr_row][curr_col-1] == 'F' ) ){

      check = depth_first_search( the_maze, curr_row, curr_col-1 );

  }

  // Up
  if( check == 0 && curr_row-1 >= 0 && ( the_maze[curr_row-1][curr_col] == ' '
    || the_maze[curr_row-1][curr_col] == 'F' ) ){

      check = depth_first_search( the_maze, curr_row-1, curr_col );

  }

  // Check right
  if( check == 0 && curr_col+1 < COLS && ( the_maze[curr_row][curr_col+1] == ' '
    || the_maze[curr_row][curr_col+1] == 'F' ) ){

      check = depth_first_search( the_maze, curr_row, curr_col+1 );

  }

  // Up
  if( check == 0 && curr_row+1 < ROWS && ( the_maze[curr_row+1][curr_col] == ' '
    || the_maze[curr_row+1][curr_col] == 'F' ) ){

      check = depth_first_search( the_maze, curr_row+1, curr_col );

  }

  // Reset to a space if empty
  if( check == 0 ){
    the_maze[curr_row][curr_col] = ' ';
    print_maze( the_maze );
  }

  return check;
}
