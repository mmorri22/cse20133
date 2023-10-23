#include <stdio.h>
#include <stdlib.h>

typedef struct smaller_struct{

    double the_double;
    int the_int;

}smaller_struct;

typedef struct first_struct{
    char first_char;
    double first_double;
    char second_char;
    double second_double;
    float first_float;
    int first_int;
    float second_float;
    float third_float;
    char third_char;
}first_struct;

// Improved Memory
typedef struct fixed_struct{
    double first_double;
    double second_double;
    float first_float;
    float second_float;
    float third_float;
    int first_int;
    char first_char;
    char second_char;
    char third_char;
}fixed_struct;


int main(){

    smaller_struct* int_example = (smaller_struct*)malloc( sizeof(smaller_struct) );
    fprintf( stdout, "Size of smaller_struct = %lu\n", sizeof(smaller_struct) );
    fprintf( stdout, "Any struct larger than 8 bytes must be a multiple of 8\n");
    fprintf( stdout, "The locations:\n");
    fprintf( stdout, "Base address  : %p\n", int_example);
    fprintf( stdout, "the_int       : %p\n", &int_example->the_double);
    fprintf( stdout, "the_int       : %p\n", &int_example->the_int);

    fprintf( stdout, "----------------------\n");

    first_struct* example_struct = (first_struct*)malloc( sizeof(first_struct) );

    size_t optimal_size = 3*sizeof(float) + 2*sizeof(double) + 3*sizeof(char) + sizeof(int);
    fprintf( stdout, "Size of optimal first_struct = %lu\n", optimal_size );
    fprintf( stdout, "Minimal size of first_struct = 40\n" );

    fprintf( stdout, "Size of first_struct = %lu\n", sizeof(first_struct) );

    fprintf( stdout, "The locations:\n");
    fprintf( stdout, "Base address  : %p\n", example_struct);
    fprintf( stdout, "first_char    : %p\n", &example_struct->first_char);
    fprintf( stdout, "first_double  : %p\n", &example_struct->first_double);
    fprintf( stdout, "second_char   : %p\n", &example_struct->second_char);
    fprintf( stdout, "second_double : %p\n", &example_struct->second_double);
    fprintf( stdout, "first_float   : %p\n", &example_struct->first_float);
    fprintf( stdout, "first_int     : %p\n", &example_struct->first_int);
    fprintf( stdout, "second_float  : %p\n", &example_struct->second_float);
    fprintf( stdout, "third_float   : %p\n", &example_struct->third_float);
    fprintf( stdout, "third_char    : %p\n", &example_struct->third_char);

    fprintf( stdout, "----------------------\n");

    fixed_struct* updated_struct = (fixed_struct*)malloc( sizeof(fixed_struct) );
    fprintf( stdout, "Size of fixed_struct = %lu\n", sizeof(fixed_struct) );

    fprintf( stdout, "The locations:\n");
    fprintf( stdout, "Base address  : %p\n", updated_struct);
    fprintf( stdout, "first_double  : %p\n", &updated_struct->first_double);
    fprintf( stdout, "second_double : %p\n", &updated_struct->second_double);
    fprintf( stdout, "first_float   : %p\n", &updated_struct->first_float);
    fprintf( stdout, "second_float  : %p\n", &updated_struct->second_float);
    fprintf( stdout, "third_float   : %p\n", &updated_struct->third_float);
    fprintf( stdout, "first_int     : %p\n", &updated_struct->first_int);
    fprintf( stdout, "first_char    : %p\n", &updated_struct->first_char);
    fprintf( stdout, "second_char   : %p\n", &updated_struct->second_char);
    fprintf( stdout, "third_char    : %p\n", &updated_struct->third_char);

    /* Free all memory */
    free(int_example);
    free(example_struct);
    free(updated_struct);

    return EXIT_SUCCESS;
}