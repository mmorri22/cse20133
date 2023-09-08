#include <stdio.h>

/* function prototype */
void function (int a, int * b);

int main()
{
   int m = 3;
   int n = 5;

   fprintf( stdout, "main - int m = %d at %p\n", m, &m);
   fprintf( stdout, "main - int n = %d at %p\n", n, &n);

   function(m, &n) ;

   fprintf( stdout, "main - int m = %d at %p\n", m, &m);
   fprintf( stdout, "main - int n = %d at %p\n", n, &n);

   return 0;
}

void function (int a, int * b){

  fprintf( stdout, "before function - int a = %d at %p\n", a, &a);

  /* Step 1 - How would we print the address and value of what b is pointing at? */

   a = 7 ;
   *b = a ;
   b = &a ;
   *b = 4 ;

   fprintf( stdout, "after function - int a = %d at %p\n", a, &a);

   /* Step 1b - How would we print the address and value of what b is pointing at? */

}
