#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b);

int main( const int argc, const char* argv[] ){

    if( argc != 3 ){
        return EXIT_FAILURE;
    }

    int first_val = atoi( argv[1] );
    int second_val = atoi( argv[2] );

    fprintf( stdout, "%d + %d = %d\n", first_val, second_val, sum(first_val, second_val) );

    return EXIT_SUCCESS;
}

int sum(int a, int b){
    return a+b;
}