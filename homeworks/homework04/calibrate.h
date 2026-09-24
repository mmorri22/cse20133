/********************************
 * File Name: calibrate.h
 * Student's Name: Brian Kernighan
 * Student's Notre Dame NetID: bkernigh@nd.edu
 * Date Started: 2/1/1978
 *******************************/

#ifndef CALIBRATE_H
#define CALIBRATE_H

/***************************
 * Function Name: read_raw
 * Pre-Conditions: int channel_number, int* raw_count
 * Post-Conditions: void
 *
 * Reads the raw count from the given channel and stores
 * it through the pointer
 **************************/
void read_raw( int channel_number, int* raw_count );

/***************************
 * Function Name: apply_gain
 * Pre-Conditions: int gain_factor, int* channel_value
 * Post-Conditions: void
 *
 * Multiplies the channel value by the gain factor using
 * repeated addition
 **************************/
void apply_gain( int gain_factor, int* channel_value );

/***************************
 * Function Name: apply_offset
 * Pre-Conditions: int offset_value, int bridge_total
 * Post-Conditions: void
 *
 * Adds the calibration offset to the bridge total
 **************************/
void apply_offset( int offset_value, int bridge_total );

/***************************
 * Function Name: sum_channels
 * Pre-Conditions: int* channel_a, int* channel_b, int* bridge_total
 * Post-Conditions: void
 *
 * Sums the two conditioned channels into the bridge total
 **************************/
void sum_channels( int* channel_a, int* channel_b, int* bridge_total );

/***************************
 * Function Name: print_reading
 * Pre-Conditions: int channel_number, int* channel_value
 * Post-Conditions: void
 *
 * Prints the channel value, the address the pointer holds,
 * and the address of the pointer parameter itself
 **************************/
void print_reading( int channel_number, int* channel_value );

/***************************
 * Function Name: print_scaled
 * Pre-Conditions: int channel_number, int* channel_value
 * Post-Conditions: void
 *
 * Prints the channel value converted to volts
 **************************/
void print_scaled( int channel_number, int* channel_value );

/***************************
 * Function Name: report_samples
 * Pre-Conditions: long unsigned int sample_count
 * Post-Conditions: void
 *
 * Prints the number of samples taken during this calibration
 **************************/
void report_samples( long unsigned int sample_count );

#endif
