#ifndef CALIBRATE_H
#define CALIBRATE_H

void read_raw( int channel, int* raw_value );
void apply_gain( int gain, int* value );
void apply_offset( int offset, int total );
void sum_channels( int* channel_a, int* channel_b, int* total );
void print_reading( int channel, int* value );
void print_scaled( int channel, int* value );
void report_samples( long unsigned int sample_count );

#endif
