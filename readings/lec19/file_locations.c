#include <stdio.h>
#include <stdlib.h>

int main( const int argc, const char* argv[] ){

  fprintf( stdout, "stdout on the stack at %p\n", stdout );
  fprintf( stdout, "stdin on the stack at %p\n", stdin );

  return EXIT_SUCCESS;
}
