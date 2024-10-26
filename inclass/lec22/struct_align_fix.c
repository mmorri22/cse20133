#include <stdio.h>
#include <stdlib.h>

// Write the updated example struct


int main(){

    first_struct* example_struct = (first_struct*)malloc( sizeof(first_struct) );

    size_t optimal_size = 3*sizeof(float) + 2*sizeof(double) + 2*sizeof(char) + sizeof(int);
    fprintf( stdout, "Size of optimal first_struct = %lu\n", optimal_size );
    fprintf( stdout, "Size of first_struct = %lu\n", sizeof(first_struct) );

    fprintf( stdout, "The locations:\n");
    fprintf( stdout, "Base address  : %p\n", example_struct);
    fprintf( stdout, "first_char    : %p\n", &example_struct->first_char);
    fprintf( stdout, "second_char   : %p\n", &example_struct->second_char);
    fprintf( stdout, "third_char    : %p\n", &example_struct->third_char);
    fprintf( stdout, "first_int     : %p\n", &example_struct->first_int);
    fprintf( stdout, "first_float   : %p\n", &example_struct->first_float);
    fprintf( stdout, "second_float  : %p\n", &example_struct->second_float);
    fprintf( stdout, "third_float   : %p\n", &example_struct->third_float);
    fprintf( stdout, "first_double  : %p\n", &example_struct->first_double);
    fprintf( stdout, "second_double : %p\n", &example_struct->second_double);

    free(example_struct);

    return EXIT_SUCCESS;
}