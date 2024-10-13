#include <stdio.h>
#include <stdlib.h>

// struct definition
typedef struct simple{
	int the_int;
	double the_double;
	float the_float;
} simple;

/***************************************************************
 * Function Name: print_dynamic_struct
 * Pre-Conditions: simple* dynamic_struct
 * Post-Conditions: void
 *
 * Prints the addresses and data values of the struct.
 **************************************************************/
void print_dynamic_struct( simple* dynamic_struct );

int main(){
      //create a struct on the heap
      simple* dynamic_struct = (simple *)malloc( sizeof(simple) );

			dynamic_struct->the_int = 45;
			dynamic_struct->the_float = (float)-1.1;
			dynamic_struct->the_double = 45.1;

			fprintf( stdout, "In main: %p %p\n", &dynamic_struct, dynamic_struct);
			print_dynamic_struct( dynamic_struct );

			// Always free dynamically allocated memory
			free( dynamic_struct );

      return 0;
}

void print_dynamic_struct( simple* dynamic_struct ){

	fprintf( stdout, "In print_dynamic_struct: %p %p\n", &dynamic_struct, dynamic_struct);
	fprintf( stdout, "%d %p\n", dynamic_struct->the_int, &(dynamic_struct->the_int));
	fprintf( stdout, "%f %p\n", dynamic_struct->the_float, &(dynamic_struct->the_float));
	fprintf( stdout, "%lf %p\n", dynamic_struct->the_double, &(dynamic_struct->the_double));

}
