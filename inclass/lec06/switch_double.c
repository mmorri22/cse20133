#include <stdio.h>

int main(void){

  /* Switch variable */
  double ND_Class = 2;

  /* Deliberate compiler error will be stated at Line 9 */
  switch( ND_Class ){

		case 0:
			fprintf( stdout, "Freshman!\n" );
			break;

		case 1:
			fprintf( stdout, "Sophomore!\n" );
			break;

		case 2:
			fprintf( stdout, "Junior!\n" );
			break;

		case 3:
			fprintf( stdout, "Senior!\n" );
			break;

		default:
			fprintf( stdout, "Error!\n" );
			fprintf( stdout, "Should be 0-3, is %lf\n", ND_Class );
			break;
	}

  return 0;
}
