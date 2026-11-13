#include <stdio.h>
#include <stdlib.h>

int main( const int argc, const char* argv[] ){

  FILE* print_out =  fopen("example_output.txt", "w");

  if( print_out == NULL ){
      exit(-1);
  }

  fprintf( print_out, "stdout on the stack at %p\n", stdout );
  fprintf( print_out, "stdin  on the stack at %p\n", stdin );
  fprintf( print_out, "print_out  on the heap at %p\n", print_out );

  fprintf( print_out, "Address and value of argc: %p %d\n", &argc, argc );
  fprintf( print_out, "Register and Base Address of argv: %p %p\n", &argv, argv );

  int iter;
  for( iter = 0; iter < argc; ++iter ){
      fprintf( stdout, "Printing to stdout: %s %p\n", argv[iter], &argv[iter] );
      fprintf( print_out, "Printing to print_out: %s %p\n", argv[iter], &argv[iter] );
  }

  fclose(print_out);

  return EXIT_SUCCESS;
}
