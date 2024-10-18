#include <stdio.h>
#include <stdlib.h>

typedef struct prob_struct{

  unsigned int the_uint;
  int the_int;
  float the_float;
  double the_double;

}prob_struct;

int main( const int argc, const char* argv[] ){

  if( argc != 5 ){
    fprintf( stderr, "Need exactly 5 inputs\n");
    exit(-1);
  }

  fprintf( stdout, "%p %d\n", &argc, argc );
  fprintf( stdout, "%p %p\n", &argv, argv );

  int iter;
  for( iter = 0; iter < argc; ++iter ){
    fprintf( stdout, "%p %p %s\n", &argv[iter], argv[iter], argv[iter] );
  }

  prob_struct static_str = { (unsigned int) atoi(argv[1]), atoi(argv[2]),
    (float)atof(argv[3]), atof(argv[4]) };

  fprintf( stdout, "%p\n", &static_str );
  fprintf( stdout, "%p %u\n", &static_str.the_uint, static_str.the_uint );
  fprintf( stdout, "%p %d\n", &static_str.the_int, static_str.the_int );
  fprintf( stdout, "%p %f\n", &static_str.the_float, static_str.the_float );
  fprintf( stdout, "%p %f\n", &static_str.the_double, static_str.the_double );

  prob_struct* dyn_str = (prob_struct*)malloc( sizeof(prob_struct) );
  dyn_str->the_uint = (unsigned int) atoi(argv[1]);
  dyn_str->the_int = atoi(argv[2]);
  dyn_str->the_float = (float)atof(argv[3]);
  dyn_str->the_double = atof(argv[4]);

  fprintf( stdout, "%p %p\n", &dyn_str, dyn_str );
  fprintf( stdout, "%p %u\n", &dyn_str->the_uint, dyn_str->the_uint );
  fprintf( stdout, "%p %d\n", &dyn_str->the_int, dyn_str->the_int );
  fprintf( stdout, "%p %f\n", &dyn_str->the_float, dyn_str->the_float );
  fprintf( stdout, "%p %f\n", &dyn_str->the_double, dyn_str->the_double );

  free(dyn_str);

  return EXIT_SUCCESS;
}
