#include <stdio.h>

int main(){

	/* Variables */
	int fact_num = 6;
	int fact_result = 1;

	int iter;
	for( iter = 1; iter <= fact_num; iter++ ){

		fact_result = fact_result * iter;

	}

	fprintf( stdout, "%d! = %d\n", fact_num, fact_result );

	return 0;

}
