#include "Student.h"

Student::Student(std::string nameIn) : name(nameIn), mainCourse() {}

void Student::setMainCourse(std::string mainCourseIn){
	
	mainCourse = mainCourseIn;
	
}

std::string Student::getName() const{
	return name;
}

std::string Student::getMainCourse() const{
	return mainCourse;
}

std::ostream& operator<<(std::ostream& out, const Student& S){
	
	out << S.name << " says: ";
	out << "May I please have a ";
	out << S.mainCourse << "?";
	
	return out;
}

