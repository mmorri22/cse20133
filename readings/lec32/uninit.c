#include <stdio.h>

int main(int argc, char *argv[])
{
	(void)argv;
	int mode;
	if (argc > 1) {
		mode = 1;
	}
	fprintf(stdout, "mode = %d\n", mode);
	return 0;
}
