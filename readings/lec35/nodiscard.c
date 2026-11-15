#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERR_SENSOR -1

/* [[nodiscard]] tells the compiler: ignoring this return value is a mistake */
[[nodiscard]] int read_sensor(int channel, double *value)
{
	if (channel < 0 || channel > 3) {
		return ERR_SENSOR;	/* there are only 4 channels */
	}
	*value = 20.0 + 1.5 * channel;
	return OK;
}

int main(void)
{
	double temp = 0.0;

	/* Channel 7 does not exist, and we never check */
	read_sensor(7, &temp);

	fprintf(stdout, "Temperature: %.1f C\n", temp);
	return EXIT_SUCCESS;
}
