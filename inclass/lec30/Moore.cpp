#include <iostream>
#include <cstdlib>

#define SIZE 25

void printOutput( char* output_str ){
	
	for( long unsigned int iter = 0; iter < SIZE; ++iter ){
		
		std::cout << output_str[iter];
		
	}
	
	std::cout << std::endl;
}


int main(){
	
	int input_val = 0;
	unsigned int state = 0;
	long unsigned int iter = 0;
	
	char* outputVec = new char[ SIZE ];
	
	while( input_val != 2 && iter < 25 ){
		
		std::cout << "Input 0 or 1 for the next state (or 2 to end): ";

		std::cin >> input_val;
		
		if( input_val == 2 ){
			break;
		}
		
		switch( state ){
			
			case 0:	// q1 is 0
				
				if( input_val == 0 ){
					state = 1;
					outputVec[iter] = '2';
				}
				else{
					state = 0;
					outputVec[iter] = '1';
				}
				break;
			
			case 1:	// q2 is 1
				
				if( input_val == 0 ){
					state = 2;
					outputVec[iter] =  '3';
				}
				else{
					state = 0;
					outputVec[iter] = '1';
				}
				break;
				
			case 2:	// q3 is 2
				
				if( input_val == 0 ){
					state = 1;
					outputVec[iter] = '2';
				}
				else{
					state = 0;
					outputVec[iter] =  '1';
				}
				break;
			
			default:
				fprintf( stdout, "Invalid state\n" );
				return EXIT_FAILURE;
				break;
			
		}
		
		++iter;
	}
	
	/* Print the Results */
	printOutput( outputVec );

	/* Delete the dynamic memory */
	delete [] outputVec;
	
}
