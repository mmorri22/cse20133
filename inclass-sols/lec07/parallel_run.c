#include "parallel_lib.h"

int main( void ){

    double R_sum = add_resis( 10, 22.7, 13.5 );

    double final = invert( R_sum );

    print( 10, 22.7, 13.5, final );

    return 0;
}