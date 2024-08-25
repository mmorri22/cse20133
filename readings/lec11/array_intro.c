#include <stdio.h>

int main(){

	unsigned int iterator = 0;
	int sample[] = {1, 7, 3, 22, 5};

	for(iterator = 0; iterator < 5; ++iterator){

		fprintf( stdout, "sample[%u] = %d\n", iterator, sample[iterator] );

	}

	return 0;
}
