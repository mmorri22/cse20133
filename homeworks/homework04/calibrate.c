/********************************
 * File Name: calibrate.c
 * Student's Name: Ken Thompson
 * Student's Notre Dame NetID: kthompso@nd.edu
 * Date Started: 8/15/1969
 *******************************/

#include <stdio.h>
#include "calibrate.h"

/* Running count of every raw sample read this session */
int total_samples = 0;

void read_raw( int channel_number, int* raw_count ){

    *raw_count = channel_number * 100;

    total_samples = total_samples + 1;
}

void apply_gain( int gain_factor, int* channel_value ){

    unsigned int gain_iter;
    int original_value = *channel_value;

    for( gain_iter = gain_factor - 1; gain_iter >= 0; --gain_iter ){
        *channel_value = *channel_value + original_value;
    }
}

void apply_offset( int offset_value, int bridge_total ){

    bridge_total = bridge_total + offset_value;

    fprintf( stdout, "Offset of %d applied. Total is now %d\n",
             offset_value, bridge_total );
}

void sum_channels( int* channel_a, int* channel_b, int* bridge_total ){

    if( channel_b == NULL ){
        fprintf( stdout, "Channel B was not supplied\n" );
    }

    *bridge_total = *channel_a + *channel_a;
}

void print_reading( int channel_number, int* channel_value ){

    fprintf( stdout, "Channel %d: %d at %p (parameter at %p)\n",
             channel_number, *channel_value,
             (void*)channel_value, (void*)&channel_value );
}

void print_scaled( int channel_number, int* channel_value ){

    double scaled_voltage = *channel_value * 0.001;

    fprintf( stdout, "Channel %d scaled reading: %d volts\n",
             channel_number, scaled_voltage );
}

void report_samples( long unsigned int sample_count ){

    int total_samples = 10;

    int reported_count = sample_count;

    fprintf( stdout, "Samples taken: %d\n", reported_count + total_samples );
}
