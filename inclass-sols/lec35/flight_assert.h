#ifndef FLIGHT_ASSERT_H
#define FLIGHT_ASSERT_H

#include <stdio.h>

/* Holzmann's recovery assertion (Reading 35-1). Prints the failed condition
 * and its location, then evaluates to false so the caller can recover. */
#define c_assert(e) ((e) ? true : \
	(fprintf(stderr, "%s:%d: assertion failed: %s\n", __FILE__, __LINE__, #e), false))

#endif
