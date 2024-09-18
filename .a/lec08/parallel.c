#include <stdio.h>
#include <math.h>

double add_resis( double R1, double R2, double R3 );

double invert( double R_sum );

void print( double R1, double R2, double R3, double R_sum );

int main( void ){
	
	double R_sum = add_resis( 10, 22.7, 13.5 );
	
	double final = invert( R_sum );
	
	print( 10, 22.7, 13.5, final );
	
	return 0;
}

double add_resis( double R1, double R2, double R3 ){
	
	return 1/R1 + 1/R2 + 1/R3;
	
}

double invert( double R_sum ){
	
	return 1/R_sum;
}

void print( double R1, double R2, double R3, double R_sum ){
	
	fprintf( stdout, "Resistance in parallel of %lf, %lf, and %lf is %lf\n",
		R1, R2, R3, R_sum );
}