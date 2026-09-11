#include <stdio.h>

int sub_func( int val_1, int val_2 ){
  return val_1 - val_2;
}

int add_func( int val_1, int val_2 ){
  return val_1 + sub_func(val_2, val_1);
}

int main(){

  int first_num = 10;
  int second_num = 20;

  int result_val = add_func( first_num, second_num );

  fprintf( stdout, "%d\n", result_val );

  return 0;
}
