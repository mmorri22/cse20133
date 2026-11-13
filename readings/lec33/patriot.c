#include <stdio.h>
#include <stdint.h>

/*
 * The Patriot system counted time in tenths of a second and converted the
 * count to seconds by multiplying by 0.1, stored as a binary fraction with
 * 23 bits after the binary point. 0.1 is a repeating fraction in binary, so
 * the bits that did not fit were simply chopped off.
 */
#define FRACTION_BITS 23

int main(void)
{
	/* 0.1 * 2^23 = 838860.8, chopped to the integer 838860 */
	const uint64_t tenth_fixed = 838860;
	const double scale = (double)(1UL << FRACTION_BITS);

	double stored_tenth = (double)tenth_fixed / scale;
	fprintf(stdout, "Stored value of 0.1: %.12f\n", stored_tenth);
	fprintf(stdout, "Error per tick:      %.12f seconds\n\n", 0.1 - stored_tenth);

	fprintf(stdout, "%8s %14s %14s %12s\n", "Hours", "True time (s)", "Patriot (s)", "Error (s)");
	const uint64_t hours[] = { 1, 8, 20, 48, 72, 100 };
	for (int i = 0; i < 6; i++) {
		uint64_t ticks = hours[i] * 3600UL * 10UL;	/* ten ticks per second */
		double true_time = (double)hours[i] * 3600.0;
		double patriot_time = (double)(ticks * tenth_fixed) / scale;
		fprintf(stdout, "%8lu %14.4f %14.4f %12.4f\n", (unsigned long)hours[i],
			true_time, patriot_time, true_time - patriot_time);
	}
	return 0;
}
