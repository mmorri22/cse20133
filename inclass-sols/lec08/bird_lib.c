#include "bird_lib.h"

void calc_flaps(){

    unsigned int time = 60;
    unsigned int start = 0;

    unsigned int num_flaps = 0;

    while( start < time ){

        if( start % 2 == 0 )
            num_flaps +=  50;

        else
            num_flaps += 75;

        print_flap( num_flaps );

        start++;
    }

}

void print_flap( unsigned int num_flaps ){

    fprintf( stdout, "%u\n", num_flaps);
}