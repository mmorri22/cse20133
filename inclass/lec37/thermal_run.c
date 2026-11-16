/*
 * In-Class Lecture 37 - Thermal fault protection mission run.
 * You do not need to change this file. It uses your four functions to fly
 * the scenario in a telemetry file, then prints the event report log.
 */
#include <stdio.h>
#include <stdlib.h>

#include "fault_protection.h"

enum {
	MAX_ROWS = 1000,	/* Rule 2: the file read is bounded */
	OVER_TEMP = 4500,	/* 45.00 C */
	HEATER_ON_BELOW = 1950,	/* 19.50 C */
	HEATER_OFF_ABOVE = 2050	/* 20.50 C */
};

static const char *severity_name(evr_severity s)
{
	switch (s) {
	case EVR_INFO:  return "INFO ";
	case EVR_WARN:  return "WARN ";
	case EVR_ERROR: return "ERROR";
	case EVR_FATAL: return "FATAL";
	}
	return "?????";
}

static void print_log(const evr_log *log)
{
	int start = (log->count < EVR_CAPACITY) ? 0 : log->next;
	fprintf(stdout, "\nEvent report log: %d stored, %d overwritten\n",
		log->count, log->total - log->count);
	for (int i = 0; i < log->count; i++) {
		const evr *e = &log->entries[(start + i) % EVR_CAPACITY];
		fprintf(stdout, "  t=%6u ms  %s  %s\n", e->time_ms, severity_name(e->severity), e->msg);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <telemetry.csv>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "The file %s does not exist\n", argv[1]);
		return EXIT_FAILURE;
	}

	evr_log log = { .count = 0, .next = 0, .total = 0 };
	leaky_bucket bucket = { 0, 2, 1, 6, 20 };
	int heater_on = 0;
	int safe_mode = 0;
	char msg[EVR_MSG_LEN];

	evr_add(&log, 0U, EVR_INFO, "thermal fault protection started");

	for (int row = 0; row < MAX_ROWS && !safe_mode; row++) {
		unsigned t = 0;
		tmr_reading r;
		if (fscanf(fp, "%u,%hd,%hd,%hd", &t, &r.copy[0], &r.copy[1], &r.copy[2]) != 4) {
			break;
		}

		int16_t temp = 0;
		int dissenter = NO_DISSENT;
		int bad = 0;

		if (vote(&r, &temp, &dissenter) != VOTE_OK) {
			snprintf(msg, sizeof msg, "no quorum: %d %d %d", r.copy[0], r.copy[1], r.copy[2]);
			evr_add(&log, t, EVR_ERROR, msg);
			bad = 1;
		}
		else {
			if (dissenter != NO_DISSENT) {
				snprintf(msg, sizeof msg, "channel %d outvoted (%d vs %d)",
					 dissenter, r.copy[dissenter], temp);
				evr_add(&log, t, EVR_WARN, msg);
			}
			if (temp > OVER_TEMP) {
				bad = 1;
			}

			int command = heater_command(heater_on, temp, HEATER_ON_BELOW, HEATER_OFF_ABOVE);
			if (command != heater_on) {
				heater_on = command;
				snprintf(msg, sizeof msg, "heater %s at %d.%02d C",
					 heater_on ? "ON" : "OFF", temp / 100, temp % 100);
				evr_add(&log, t, EVR_INFO, msg);
			}
		}

		if (bucket_update(&bucket, bad) == 1) {
			evr_add(&log, t, EVR_FATAL, "SAFE MODE: thermal fault confirmed");
			safe_mode = 1;
		}
	}
	fclose(fp);

	print_log(&log);
	return safe_mode ? EXIT_FAILURE : EXIT_SUCCESS;
}
