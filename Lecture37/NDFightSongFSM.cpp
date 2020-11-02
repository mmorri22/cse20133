#include <iostream>
#include <cstdlib>

#define COUT std::cout
#define ENDL std::endl

int main(){
	
	/* Time through the song and state */
	unsigned int timeThrough = 0;
	unsigned int state = 0;
	
	/* Keep going until we reach the end */
	while ( state <= 5 ){
		
		switch( state ){
			
			case 0:
				COUT << "Begin song" << ENDL;
				state = 1;
				break;
				
			case 1:
				COUT << "Play Measures 1-20" << ENDL;
				state = 2;
				break;
				
			case 2:
				COUT << "Play Measures 21-34" << ENDL;
				if( timeThrough == 0 ){
					timeThrough = 1;
					state = 3;
				}
				else{
					COUT << "Second Time Through. Don't repeat." << ENDL;
					state = 4;
				}
				break;
				
			case 3:
				COUT << "Play Measures 35-36" << ENDL;
				COUT << "Go back to measure 21" << ENDL;
				state = 2;
				break;
				
			case 4:
				COUT << "Play Measures 37-41" << ENDL;
				state = 5;
				break;
				
			case 5:
				COUT << "End of song!" << ENDL;
				state = 6;
				break;
				
			default:
				COUT << "Invalid state" << ENDL;
				exit(-1);
				break;
			
		}
		
	}
	
	return 0;
}