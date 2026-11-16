/*
 * In-Class Lecture 37 - Fault Protection
 *
 * INSTRUCTOR SOLUTION
 */
#include <stddef.h>
#include <string.h>

#include "fault_protection.h"

/* Step 1: majority vote that also names the channel that was outvoted */
int vote(const tmr_reading *r, int16_t *result, int *dissenter)
{
	if (r == NULL || result == NULL || dissenter == NULL) {
		return VOTE_NO_QUORUM;
	}
	const int16_t a = r->copy[0];
	const int16_t b = r->copy[1];
	const int16_t c = r->copy[2];

	if (a == b && b == c) {
		*result = a;
		*dissenter = NO_DISSENT;
		return VOTE_OK;
	}
	if (a == b) {
		*result = a;
		*dissenter = 2;
		return VOTE_OK;
	}
	if (a == c) {
		*result = a;
		*dissenter = 1;
		return VOTE_OK;
	}
	if (b == c) {
		*result = b;
		*dissenter = 0;
		return VOTE_OK;
	}
	*dissenter = NO_DISSENT;
	return VOTE_NO_QUORUM;
}

/* Step 2: fill on bad, leak on good, never below 0 or above max */
int bucket_update(leaky_bucket *b, int bad)
{
	if (b == NULL) {
		return -1;
	}
	if (bad) {
		b->level += b->fill;
		if (b->level > b->max) {
			b->level = b->max;
		}
	}
	else {
		b->level -= b->leak;
		if (b->level < 0) {
			b->level = 0;
		}
	}
	return (b->level >= b->trip) ? 1 : 0;
}

/* Step 3: two thresholds, and no change inside the band */
int heater_command(int heater_on, int16_t temp, int16_t on_below, int16_t off_above)
{
	if (temp < on_below) {
		return 1;
	}
	if (temp > off_above) {
		return 0;
	}
	return heater_on;
}

/* Step 4: ring buffer that keeps the newest EVR_CAPACITY events */
void evr_add(evr_log *log, uint32_t time_ms, evr_severity severity, const char *msg)
{
	if (log == NULL || msg == NULL) {
		return;
	}
	evr *e = &log->entries[log->next];
	e->time_ms = time_ms;
	e->severity = severity;
	strncpy(e->msg, msg, EVR_MSG_LEN - 1);
	e->msg[EVR_MSG_LEN - 1] = '\0';

	log->next = (log->next + 1) % EVR_CAPACITY;
	if (log->count < EVR_CAPACITY) {
		log->count++;
	}
	log->total++;
}
