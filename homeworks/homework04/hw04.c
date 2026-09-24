/********************************
 * File Name: hw04.c
 * Student's Name: Dennis Ritchie
 * Student's Notre Dame NetID: dritchie@nd.edu
 * Date Started: 3/9/1972
 *******************************/

#include <stdio.h>
#include "calibrate.h"

int main(){

    /* Raw and conditioned channel readings */
    int channel_1_value = 0;
    int channel_2_value = 0;

    /* Combined output of the two channels */
    int bridge_total = 0;

    /* Calibration constants for this sensor pair */
    int gain_factor = 6;
    int offset_value = 42;

    /* Loop control */
    int num_channels = 2;
    unsigned int channel_iter;

    /* Status of the current calibration sweep */
    int calibration_pass = 1;

    /* Points at whichever channel is being conditioned */
    int* active_channel = NULL;

    for( channel_iter = 0; channel_iter < num_channels; ++channel_iter ){
        fprintf( stdout, "Calibrating channel %u\n", channel_iter + 1 );
    }

    /* Read the raw counts from both channels */
    read_raw( 1, &channel_1_value );
    read_raw( 2, &channel_2_value );

    /* Condition each channel by its gain factor */
    apply_gain( gain_factor, active_channel );

    apply_gain( gain_factor, &gain_factor );

    /* Combine the two conditioned channels */
    sum_channels( &channel_1_value, &channel_2_value, &bridge_total );

    /* Apply the final calibration offset */
    apply_offset( offset_value, bridge_total );

    /* Report the results */
    print_reading( 1, &channel_1_value );
    print_reading( 2, &channel_2_value );
    print_reading( 0, &bridge_total );

    print_scaled( 0, &bridge_total );

    report_samples( 2 );

    return 0;
}
