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

int main()
{

    long unsigned int pascal_size;

    fprintf( stdout, "Enter the size of the Pascal Triangle: ");

    fscanf( stdin, "%lu", &pascal_size );

    int** pascal = (int **)malloc( pascal_size * sizeof(int *) );

    alloc_mem( pascal, pascal_size );

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
