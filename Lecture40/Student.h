#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student{
	
	private:
		std::string name;
		std::string mainCourse;
		
	public:
	
		Student(std::string nameIn);

		void setMainCourse(std::string mainCourseIn);
		
		std::string getName() const;
		
		std::string getMainCourse() const;
		
		friend std::ostream& operator<<(std::ostream& out, const Student& S);
	
};


#endif

