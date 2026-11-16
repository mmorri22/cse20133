/*
 * In-Class Lecture 37 - Fault Protection test harness.
 * You do not need to change this file. Make every test pass.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fault_protection.h"

static int passed = 0;
static int failed = 0;

static void check(int number, const char *name, int ok)
{
	fprintf(stdout, "Test %2d: %-52s %s\n", number, name, ok ? "PASS" : "FAIL");
	if (ok) {
		passed++;
	}
	else {
		failed++;
	}
}

int main(void)
{
	int16_t v = 0;
	int d = 99;

	/* Step 1 - vote */
	tmr_reading r = { { 2150, 2150, 2150 } };
	check(1, "vote: all three agree", vote(&r, &v, &d) == VOTE_OK && v == 2150 && d == NO_DISSENT);

	r = (tmr_reading){ { 2150, 3174, 2150 } };
	check(2, "vote: channel 1 disagrees", vote(&r, &v, &d) == VOTE_OK && v == 2150 && d == 1);

	r = (tmr_reading){ { 9999, 2150, 2150 } };
	check(3, "vote: channel 0 disagrees", vote(&r, &v, &d) == VOTE_OK && v == 2150 && d == 0);

	r = (tmr_reading){ { 2150, 2150, -7 } };
	check(4, "vote: channel 2 disagrees", vote(&r, &v, &d) == VOTE_OK && v == 2150 && d == 2);

	r = (tmr_reading){ { 2150, 2151, 2152 } };
	check(5, "vote: no quorum is reported", vote(&r, &v, &d) == VOTE_NO_QUORUM);

	check(6, "vote: NULL reading is rejected", vote(NULL, &v, &d) == VOTE_NO_QUORUM);

	/* Step 2 - bucket_update */
	leaky_bucket b = { 0, 2, 1, 6, 20 };
	check(7, "bucket: one bad sample does not trip", bucket_update(&b, 1) == 0 && b.level == 2);
	check(8, "bucket: a good sample drains it", bucket_update(&b, 0) == 0 && b.level == 1);

	b.level = 0;
	check(9, "bucket: never drains below zero", bucket_update(&b, 0) == 0 && b.level == 0);

	b.level = 0;
	(void)bucket_update(&b, 1);
	(void)bucket_update(&b, 1);
	check(10, "bucket: three bad samples trip it", bucket_update(&b, 1) == 1 && b.level == 6);

	for (int i = 0; i < 50; i++) {
		(void)bucket_update(&b, 1);
	}
	check(11, "bucket: level stops at max", b.level == 20);
	check(12, "bucket: NULL is rejected", bucket_update(NULL, 1) == -1);

	/* Step 3 - heater_command */
	check(13, "heater: turns on below the band", heater_command(0, 1940, 1950, 2050) == 1);
	check(14, "heater: turns off above the band", heater_command(1, 2060, 1950, 2050) == 0);
	check(15, "heater: stays ON inside the band", heater_command(1, 2000, 1950, 2050) == 1);
	check(16, "heater: stays OFF inside the band", heater_command(0, 2000, 1950, 2050) == 0);

	/* Step 4 - evr_add */
	evr_log log = { .count = 0, .next = 0, .total = 0 };
	evr_add(&log, 1000U, EVR_INFO, "heater on");
	check(17, "evr: one event is stored",
	      log.count == 1 && log.total == 1 && log.entries[0].time_ms == 1000U &&
	      log.entries[0].severity == EVR_INFO && strcmp(log.entries[0].msg, "heater on") == 0);

	evr_log log2 = { .count = 0, .next = 0, .total = 0 };
	evr_add(&log2, 5U, EVR_WARN,
		"this message is much longer than the forty-eight characters an EVR can hold");
	check(18, "evr: long message is truncated and terminated",
	      strlen(log2.entries[0].msg) == EVR_MSG_LEN - 1 && log2.entries[0].msg[EVR_MSG_LEN - 1] == '\0');

	evr_log log3 = { .count = 0, .next = 0, .total = 0 };
	for (uint32_t i = 0; i < EVR_CAPACITY + 3; i++) {
		evr_add(&log3, i, EVR_INFO, "event");
	}
	check(19, "evr: full log keeps the newest events",
	      log3.count == EVR_CAPACITY && log3.total == EVR_CAPACITY + 3 &&
	      log3.entries[log3.next].time_ms == 3U);

	evr_add(NULL, 0U, EVR_FATAL, "nobody home");
	evr_add(&log3, 0U, EVR_FATAL, NULL);
	check(20, "evr: NULL log or message is ignored", log3.total == EVR_CAPACITY + 3);

	fprintf(stdout, "\n%d passed, %d failed\n", passed, failed);
	return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
