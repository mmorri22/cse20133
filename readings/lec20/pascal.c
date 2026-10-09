#include <stdio.h>
#include <stdlib.h>

/***************************************************************
 * Function Name: alloc_mem
 * Pre-Conditions: int** pascal, long unsigned int pascal_size
 * Post-Conditions: void
 *
 * Passes int** array by reference, and allocates int* array of increasing
 * increasing size from 1 to pascal_size
 **************************************************************/
void alloc_mem( int** pascal, long unsigned int pascal_size );

/***************************************************************
 * Function Name: free_mem
 * Pre-Conditions: int** pascal, long unsigned int pascal_size
 * Post-Conditions: void
 *
 * Passes int** array by reference and frees all the int* arrays
 **************************************************************/
void free_mem( int** pascal, long unsigned int pascal_size );

/***************************************************************
 * Function Name: populate_pascal
 * Pre-Conditions: int** pascal, long unsigned int pascal_size
 * Post-Conditions: void
 *
 * Populates the int* arrays using the Pascal Triangle method
 **************************************************************/
void populate_pascal( int** pascal, long unsigned int pascal_size );

/***************************************************************
 * Function Name: print_pascal
 * Pre-Conditions: int** pascal, long unsigned int pascal_size
 * Post-Conditions: void
 *
 * Prints the pascal Triangle of size pascal_size
 **************************************************************/
void print_pascal( int** pascal, long unsigned int pascal_size );

int main()
{

    long unsigned int pascal_size;

    fprintf( stdout, "Enter the size of the Pascal Triangle: ");

    fscanf( stdin, "%lu", &pascal_size );

    int** pascal = (int **)malloc( pascal_size * sizeof(int *) );

    alloc_mem( pascal, pascal_size );

    populate_pascal( pascal, pascal_size );

    print_pascal( pascal, pascal_size );

    free_mem( pascal, pascal_size );

    free( pascal );

    return 0;
}


void alloc_mem( int** pascal, long unsigned int pascal_size ){

    long unsigned int iter;
    for( iter = 0; iter < pascal_size; ++iter ){

        pascal[iter] = (int *)malloc( (iter+1) * sizeof(int) );
    }
}

void free_mem( int** pascal, long unsigned int pascal_size ){

    long unsigned int iter;
    for( iter = 0; iter < pascal_size; ++iter ){

        free( pascal[iter] );
    }
}

void populate_pascal( int** pascal, long unsigned int pascal_size ){

  if( pascal_size == 0 ){
    return;
  }

  pascal[0][0] = 1;
  if( pascal_size == 1 ){
    return;
  }

  pascal[1][0] = 1;
  pascal[1][1] = 1;
  if( pascal_size == 2  ){
    return;
  }

  // Every other possible case
  long unsigned int iter;
  for( iter = 2; iter < pascal_size; ++iter ){
    pascal[iter][0] = 1;
    pascal[iter][iter] = 1;

    long unsigned int jter;
    for( jter = 1; jter < iter; jter++){
      pascal[iter][jter] = pascal[iter - 1][jter] + pascal[iter - 1][jter - 1];
    }
  }

}

void print_pascal( int** pascal, long unsigned int pascal_size ){

    long unsigned int iter;
    for( iter = 0; iter < pascal_size; ++iter ){

        long unsigned int jter;
        for( jter = 0; jter <= iter; ++jter ){

            fprintf( stdout, "%d ", pascal[iter][jter] );
        }
        fprintf( stdout, "\n");
    }
}
