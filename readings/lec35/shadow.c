#include <stdio.h>
#include <stdlib.h>

int count = 0;	/* number of commands executed, visible to the whole file */

void execute_commands(int num_commands)
{
	int count = 0;	/* meant to be a loop counter, but it hides the global */
	while (count < num_commands) {
		count++;
	}
}

int main(void)
{
	execute_commands(5);
	fprintf(stdout, "Commands executed: %d\n", count);
	return EXIT_SUCCESS;
}
