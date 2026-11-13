#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint16_t a = 65535;
	uint16_t b = 1;

	uint32_t sum32 = a + b;	/* a and b are promoted to int before adding */
	uint16_t sum16 = a + b;	/* the int result is truncated on the store */

	fprintf(stdout, "sum32 = %u\n", sum32);
	fprintf(stdout, "sum16 = %u\n", sum16);
	return 0;
}
