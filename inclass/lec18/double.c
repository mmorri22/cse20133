#include <stdio.h>

int main(){

    double d_1 = 0.3;
    double d_2 = 0.2;

    double d_result = d_1 - d_2;

    if( d_result == 0.1 ){
        fprintf( stdout, "Match\n" );
    }
    else{
        fprintf( stdout, "No Match\n" );
    }

    return 0;
}