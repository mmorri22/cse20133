#include <stdio.h>

void ptr_recur_foo( int *ptr_x );
void ptr_recur_bar( int *ptr_y );

int main(){

  int x = 10;

  ptr_recur_foo(&x);

  fprintf( stdout, "%d\n", x );
  return 0;
}

void ptr_recur_foo( int* x ){

    fprintf( stdout, "In foo: x = %d\n", *x);

    int temp = *x;

    if( *x <= 0 ){
        fprintf( stdout, "Foo base case!\n");
        *x = 1;
        return;
    }

    if( *x % 2 == 0 ){
        fprintf( stdout, "Foo Case 2!\n");
        *x -= 1;
        ptr_recur_bar( x );
        *x += temp;
        return;
    }

    else{
        fprintf( stdout, "Foo Case 3!\n");
        *x -= 4;
        ptr_recur_foo( x );
        *x += temp;
    }

}

void ptr_recur_bar( int* y ){

    fprintf( stdout, "In bar: y = %d\n", *y);

    int temp = *y;

    if( *y <= 0 ){
        fprintf( stdout, "Bar base case!\n");
        *y = 2;
        return;
    }

    if( *y % 2 == 0 ){
        fprintf( stdout, "Bar Case 2!\n");
        *y -= 2;
        ptr_recur_foo( y );
        *y += temp;
        return;
    }

    else{
        fprintf( stdout, "Bar Case 3!\n");
        *y -= 3;
        ptr_recur_bar( y );
        *y += temp;
    }

}
