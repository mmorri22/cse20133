#include "matmul.h"
#include "epsilon.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(const int argc, const char *argv[])
{
	/* Delete this line once you use argc and argv */
	(void)argc; (void)argv;

	/* Part 3 - Protect the inputs and open the CSV file named by argv[1] */


	/* Part 4 - For each size m from MIN_SIZE to MAX_SIZE in steps of SIZE_STEP:
	 *   - Allocate and check five m x m matrices: a, b, c_ijk, c_ikj, c_blas
	 *   - Fill a and b with fill_matrix
	 *   - Time each method REPEATS times, storing each time in an array
	 *   - Take the median of each array
	 *   - Validate both results against c_ijk using TOLERANCE
	 *   - Print one row to stdout and one row to the CSV file
	 *   - Free all five matrices
	 */


	/* Part 5 - Measure and print machine epsilon for double and long double,
	 *          next to DBL_EPSILON and LDBL_EPSILON from <float.h> */


	return EXIT_SUCCESS;
}
