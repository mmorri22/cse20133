#include <stdio.h>

int main(){

  int the_int = 5;

  do{
      fprintf(stdout, "The value of the_int at %p = %d %x\n", &the_int, the_int, the_int);
      ++the_int;
  }while( the_int < 5 );

	fprintf( stdout, "%d\n", the_int );

  return 0;

}
