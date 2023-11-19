#include "../inc/JKFF.h"

#include <iostream>
#include <fstream>
#include <string>

#define COUT std::cout 
#define ENDL std::endl
#define IFSTREAM std::ifstream

void testJK( IFSTREAM& input_stream ){
	
	JKFF test_JK;
	
	bool clk;
	bool J_in;
	bool K_in;
	
	while( input_stream >> clk >> J_in >> K_in ){
		
		test_JK.updateVals( clk, J_in, K_in );
		
		COUT << test_JK.get_Q() << " " << test_JK.get_Q_bar() << std::endl;
		
	}
}


int main( int argc, char** argv ){
	
	if( argc != 2 ){
		
		std::cout << "Incorrect number of inputs" << std::endl;
		exit(-1);
	}
	
	IFSTREAM input_stream( argv[1] );
	
	if( !input_stream ){
		
		std::cout << argv[1] << " does not exist" << std::endl;
		exit(-1);
	}
	
	testJK( input_stream );
	
	input_stream.close();
	
	return 0;
}