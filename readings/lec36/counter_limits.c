#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* How long can a counter run before it wraps around or overflows?
 * All arithmetic is done in 64 bits (or double) so the calculation itself
 * cannot overflow. */
void print_limit(const char *description, double max_count, double ticks_per_second)
{
	double seconds = max_count / ticks_per_second;
	double days = seconds / 86400.0;

	if (days < 3650.0) {
		fprintf(stdout, "%-38s %12.1f days\n", description, days);
	}
	else {
		fprintf(stdout, "%-38s %12.0f years\n", description, days / 365.25);
	}
}

int main(void)
{
	print_limit("uint32_t milliseconds", (double)UINT32_MAX + 1.0, 1000.0);
	print_limit("int32_t hundredths of a second", (double)INT32_MAX + 1.0, 100.0);
	print_limit("uint32_t seconds", (double)UINT32_MAX + 1.0, 1.0);
	print_limit("uint64_t nanoseconds", (double)UINT64_MAX + 1.0, 1.0e9);
	return EXIT_SUCCESS;
}
