/*
 * In-Class Lecture 37 - Fault Protection
 *
 * Write the four functions below. Run "make test" after each step.
 */
#include <stddef.h>
#include <string.h>

#include "fault_protection.h"

/* Step 1 */
int vote(const tmr_reading *r, int16_t *result, int *dissenter)
{
	/* Delete these lines and write your code */
	(void)r; (void)result; (void)dissenter;
	return VOTE_NO_QUORUM;
}

/* Step 2 */
int bucket_update(leaky_bucket *b, int bad)
{
	/* Delete these lines and write your code */
	(void)b; (void)bad;
	return 0;
}

/* Step 3 */
int heater_command(int heater_on, int16_t temp, int16_t on_below, int16_t off_above)
{
	/* Delete these lines and write your code */
	(void)heater_on; (void)temp; (void)on_below; (void)off_above;
	return 0;
}

/* Step 4 */
void evr_add(evr_log *log, uint32_t time_ms, evr_severity severity, const char *msg)
{
	/* Delete this line and write your code */
	(void)log; (void)time_ms; (void)severity; (void)msg;
}
