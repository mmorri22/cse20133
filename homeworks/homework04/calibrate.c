#include <stdio.h>
#include "calibrate.h"

int total_samples = 0;

void read_raw( int channel, int* raw_value ){

    *raw_value = channel * 100;

    total_samples = total_samples + 1;
}

void apply_gain( int gain, int* value ){

    unsigned int i;
    int original = *value;

    for( i = gain - 1; i >= 0; --i ){
        *value = *value + original;
    }
}

void apply_offset( int offset, int total ){

    total = total + offset;

    fprintf( stdout, "Offset of %d applied. Total is now %d\n", offset, total );
}

void sum_channels( int* channel_a, int* channel_b, int* total ){

    if( channel_b == NULL ){
        fprintf( stdout, "Channel B was not supplied\n" );
    }

    *total = *channel_a + *channel_a;
}

void print_reading( int channel, int* value ){

    fprintf( stdout, "Channel %d: %d at %p (parameter at %p)\n",
             channel, *value, (void*)value, (void*)&value );
}

void print_scaled( int channel, int* value ){

    double scaled = *value * 0.001;

    fprintf( stdout, "Channel %d scaled reading: %d volts\n", channel, scaled );
}

void report_samples( long unsigned int sample_count ){

    int total_samples = 0;

    int reported = sample_count;

    fprintf( stdout, "Samples taken: %d\n", reported + total_samples );
}
