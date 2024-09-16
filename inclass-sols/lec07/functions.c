#include <stdio.h>

/* Function Declarations */
double double_average( double first_double, double second_double );

int main( void ){

	/* Create Variables */
	/* Note: Only create variables we are using at intermediate steps */
	double double_1 = 1;
	double double_2 = 2;

	fprintf(stdout, "%p %lf %p %lf in main\n",
		&double_1, double_1, &double_2, double_2);

	/* Average of two doubles */
	double average = double_average( double_1, double_2 );

	/* Print the result */
	fprintf( stdout, "Average is %lf\n", average );

	fprintf(stdout, "%p %lf %p %lf in main\n",
		&double_1, double_1, &double_2, double_2);
	return 0;
}

/* Function Definitions */
double double_average( double first_double, double second_double ){

	--second_double;

	fprintf(stdout, "%p %lf %p %lf in double_average\n",
		&first_double, first_double, &second_double, second_double);

	return (first_double + second_double)/2;
}