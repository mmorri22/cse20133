#include <stdio.h>
#include <stdlib.h>

int main(){

  long unsigned int array_len = 13;

  void* hello = malloc(array_len);

  fprintf( stdout, "Location of array_len is %p\n", &array_len );
  fprintf( stdout, "Location of &hello is %p\n", &hello );
  fprintf( stdout, "Location of hello is %p\n", hello );

  return 0;

}
