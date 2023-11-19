#include "../inc/JKFF.h"

/* Default Constructor */
JKFF::JKFF() : Q( false ), Q_bar( true ) {}

/* updateVals method */
void JKFF::updateVals( bool CLK, bool J_in, bool K_in ){
	
	/* If CLK is false, nothing should happen */
	if( CLK ){
		
		if( !J_in && !K_in ){
			// Do Nothing 
		}
		
		else if( J_in != K_in ){
			
			Q = J_in;
			Q_bar = K_in;
		}
		
		/* J_in and K_in = true */
		else{
			
			bool temp = Q;
			Q = Q_bar;
			Q_bar = temp;
			
		}
		
	}
	
}

/* Get Methods */

bool JKFF::get_Q() const{
	
	return Q;
	
}

bool JKFF::get_Q_bar() const{
	
	return Q_bar;
	
}