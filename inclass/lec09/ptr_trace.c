#include <stdio.h>

int main(){

  int a = 10;
  int b = 25;
  int c = 19;

  int* p1 = &a;
  int* p2 = &b;
  int* p3 = &c;

  fprintf( stdout, "%d %p\n", a, &a);
  fprintf( stdout, "%d %p\n", b, &b);
  fprintf( stdout, "%d %p\n", c, &c);

  fprintf( stdout, "%d %p %p\n", *p1, p1, &p1);
  fprintf( stdout, "%x %p %p\n", *p2, p2, &p2);
  fprintf( stdout, "%x %p %p\n", *p3, p3, &p3);

  p1 = p2;
  p3 = &a;

  fprintf( stdout, "%d %p %p\n", *p1, p1, &p1);
  fprintf( stdout, "%x %p %p\n", *p2, p2, &p2);
  fprintf( stdout, "%x %p %p\n", *p3, p3, &p3);

  return 0;
}
