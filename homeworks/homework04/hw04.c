#include <stdio.h>
#include "calibrate.h"

int main(){

    int channel_1 = 0;
    int channel_2 = 0;
    int total = 0;
    int gain = 6;
    int offset = 42;
    int num_channels = 2;
    int calibration_pass = 1;
    int* working = NULL;

    unsigned int i;

    for( i = 0; i < num_channels; ++i ){
        fprintf( stdout, "Calibrating channel %u\n", i + 1 );
    }

    read_raw( 1, &channel_1 );
    read_raw( 2, &channel_2 );

    apply_gain( gain, working );

    apply_gain( gain, &gain );

    sum_channels( &channel_1, &channel_2, &total );

    apply_offset( offset, total );

    print_reading( 1, &channel_1 );
    print_reading( 2, &channel_2 );
    print_reading( 0, &total );

    print_scaled( 0, &total );

    report_samples( 2 );

    return 0;
}
