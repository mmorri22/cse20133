#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Step 1:
// Define a type with the name new_struct
// Internals should be an int, a float, and a double
typedef struct new_struct{

  int the_int;
  float the_float;
  double the_double;

}new_struct;

int main( const int argc, const char* argv[] ){

  if( argc != 7 ){
    fprintf( stderr, "Need exactly 7 inputs\n" );
    fprintf( stderr, "./structs [int] [double] [float] [int] [double] [float]\n" );
    fprintf( stderr, "UNIX will not count valgrind --leak-check=full as inputs");
    return EXIT_FAILURE;
  }

  // Step 2: Statically Allocate a new_struct
  // 1) Statically create the struct
  // 2) Create an int using atoi
  // 3) Create a float using atof - and cast
  // 4) Create a double using atof
  new_struct static_str = { atoi(argv[1]), (float)(atof(argv[2])), atof(argv[3]) };


  // Step 3: Print use fprintf
  // 1) The address of the address of the static struct on the stack
  // 2) The value and address of the dynamic struct's int
	// 3) The value and address of the dynamic struct's float
	// 4) The value and address of the dynamic struct's double
  fprintf( stdout, "%p\n", &static_str );
  fprintf( stdout, "%p %d\n", &static_str.the_int, static_str.the_int );
  fprintf( stdout, "%p %f\n", &static_str.the_float, static_str.the_float );
  fprintf( stdout, "%p %lf\n", &static_str.the_double, static_str.the_double );

	// Step 4: Dynamically Allocate a NEW_STRUCT
  new_struct* dynamic_str = (new_struct *)malloc( sizeof(new_struct) );

	// Step 6: De-reference and set values for the int, long unsigned int, and float
  dynamic_str->the_int = atoi( argv[4] );
  dynamic_str->the_float = (float)atof( argv[5] );
  dynamic_str->the_double = atof( argv[6] );

	// Step 7: Print use fprintf
	// 1) The address of the register containing the dynamic struct pointer
  // 2) The address of the address of the dynamic struct pointer on the heap
  // 3) The value and address of the dynamic struct's int
	// 4) The value and address of the dynamic struct's float
	// 5) The value and address of the dynamic struct's double
  fprintf( stdout, "%p %p\n", &dynamic_str, dynamic_str );
  fprintf( stdout, "%p %d\n", &dynamic_str->the_int, dynamic_str->the_int);
  fprintf( stdout, "%p %f\n", &dynamic_str->the_float, dynamic_str->the_float);
  fprintf( stdout, "%p %lf\n", &dynamic_str->the_double, dynamic_str->the_double);

	// Step 5: Free the Dynamically Allocated Memory
  free(dynamic_str);


	return EXIT_SUCCESS;

};
