#include <stdio.h>

int main(){
	
	int x = 10;
	int y = -20;
	
	int* x_ptr = &x;
	int* y_ptr = &y;
	
	fprintf( stdout, "%d %x %p %p %p\n", x, x, &x, x_ptr, &x_ptr );
	fprintf( stdout, "%d %x %p %p %p\n", y, y, &y, y_ptr, &y_ptr );
	
	return 0;
}

