#include <stdio.h>

int main(void)
{
	int buf[8];
	for (int i = 0; i <= 8; i++) {
		buf[i] = 0;
	}
	fprintf(stdout, "buf[0] = %d\n", buf[0]);
	return 0;
}
