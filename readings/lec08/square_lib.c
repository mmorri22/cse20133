#include "square_lib.h"

/* Function Definitions */
int Square(int x){
	x = x * x;
	return x;
}

int SumOfSquare(int x, int y){
	int z = Square(x + y);
	return z;
}
