#include <iostream>
#include <cstdlib>
#include <vector>

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

void printOutput( std::vector<char>& outputVec ){
	
	for( long unsigned int iter = 0; iter < outputVec.size(); iter++ ){
		
		COUT << outputVec.at(iter) << " ";
		
	}
	
	COUT << ENDL;
}


int main(){
	
	char inputChar = '0';
	unsigned int state = 0;
	
	std::vector<char> outputVec;
	
	while( inputChar != '2' ){
		
		COUT << "Input 0 or 1 for the next state (or 2 to end): ";
		
		CIN >> inputChar;
		
		if( inputChar == '2' ){
			break;
		}
		
		switch( state ){
			
			case 0:	// q1 is 0
				
				if( inputChar == '0' ){
					state = 1;
					outputVec.push_back( '2' );
				}
				else{
					state = 0;
					outputVec.push_back( '1' );
				}
				break;
			
			case 1:	// q2 is 1
				
				if( inputChar == '0' ){
					state = 2;
					outputVec.push_back( '3' );
				}
				else{
					state = 0;
					outputVec.push_back( '1' );
				}
				break;
				
			case 2:	// q3 is 2
				
				if( inputChar == '0' ){
					state = 1;
					outputVec.push_back( '2' );
				}
				else{
					state = 0;
					outputVec.push_back( '1' );
				}
				break;
			
			default:
				COUT << "Invalid state" << ENDL;
				exit(-1);
				break;
			
		}
		
	}
	
	/* Print the Results */
	printOutput( outputVec );
	
}
