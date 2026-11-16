#ifndef FAULT_PROTECTION_H
#define FAULT_PROTECTION_H

#include <stdint.h>

/* ---- Voting: three redundant temperature channels, hundredths of a degree C ---- */

typedef struct {
	int16_t copy[3];
} tmr_reading;

enum { VOTE_OK = 0, VOTE_NO_QUORUM = -1 };
enum { NO_DISSENT = -1 };

/* Majority vote. On VOTE_OK, stores the majority value in *result, and the index
 * of the one disagreeing channel in *dissenter (NO_DISSENT if all three agree).
 * Returns VOTE_NO_QUORUM if no two channels agree, or if any pointer is NULL. */
int vote(const tmr_reading *r, int16_t *result, int *dissenter);

/* ---- Leaky bucket counter ---- */

typedef struct {
	int level;	/* current count, starts at 0 */
	int fill;	/* added for each bad sample */
	int leak;	/* removed for each good sample, never below 0 */
	int trip;	/* the fault is declared when level >= trip */
	int max;	/* level never goes above max */
} leaky_bucket;

/* Update the bucket with one sample. Returns 1 if level >= trip after the
 * update, 0 if not, or -1 if b is NULL. */
int bucket_update(leaky_bucket *b, int bad);

/* ---- Hysteresis heater control ---- */

/* Returns 1 (heater on) below on_below, 0 (off) above off_above, and the
 * current state heater_on anywhere in between. */
int heater_command(int heater_on, int16_t temp, int16_t on_below, int16_t off_above);

/* ---- Event reports (EVRs) ---- */

typedef enum { EVR_INFO, EVR_WARN, EVR_ERROR, EVR_FATAL } evr_severity;

enum { EVR_CAPACITY = 16, EVR_MSG_LEN = 48 };

typedef struct {
	uint32_t time_ms;
	evr_severity severity;
	char msg[EVR_MSG_LEN];
} evr;

/* A fixed-size ring buffer: when it is full, the newest event replaces the oldest */
typedef struct {
	evr entries[EVR_CAPACITY];
	int count;	/* events currently stored, at most EVR_CAPACITY */
	int next;	/* index where the next event will be written */
	int total;	/* events ever added, including overwritten ones */
} evr_log;

/* Add one event. Long messages are truncated and always '\0'-terminated.
 * Does nothing if log or msg is NULL. */
void evr_add(evr_log *log, uint32_t time_ms, evr_severity severity, const char *msg);

#endif
