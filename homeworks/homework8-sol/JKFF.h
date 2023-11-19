#ifndef JKFF_H
#define JKFF_H

class JKFF{
	
	private:
	
		bool Q;
		bool Q_bar;
		
	public:
	
		JKFF();
		
		void updateVals( bool CLK, bool J_in, bool K_in );
		
		bool get_Q() const;

		bool get_Q_bar() const;
	
};

#endif