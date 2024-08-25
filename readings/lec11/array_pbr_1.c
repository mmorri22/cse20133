#include <stdio.h>

void print_array( int sample[], int array_size );

int main(){

	int sample[5] = {1, 7, 3, 22, 5};
	int array_size = 5;

	/* Print the base address of sample to the terminal */
	fprintf(stdout, "In main - The base address of sample is %p\n", sample);

	int iter;
	for(iter = 0; iter < array_size; iter++){

		/* Print the data and address of the array element */
		fprintf( stdout, "In print_array - sample[%d] = %d at %p\n", iter, sample[iter], &sample[iter] );
	}

	/* Call the function */
	print_array( sample, array_size );

	return 0;
}


void print_array( int sample[], int array_size ){

	/* Print the base address of sample to the terminal */
	fprintf(stdout, "In print_array - The base address of sample is %p\n", sample);

	int iter;
	for(iter = 0; iter < array_size; iter++){

		/* Print the data and address of the array element */
		fprintf( stdout, "In print_array - sample[%d] = %d at %p\n", iter, sample[iter], &sample[iter] );
	}

	fprintf( stdout, "\n");
}
