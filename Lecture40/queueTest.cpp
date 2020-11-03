#include "Student.h"
#include <queue>

int main(){
	
	std::queue<Student> studentLine;
	
	Student stuSam("Samuel Battalio");
	Student stuAuna("Auna Walton");
	Student stuHind("Hind Zahour");
	Student stuPaulina("Paulina Camara");
	Student stuVinny("Vinny Karanja");
	
	stuSam.setMainCourse("Pizza");
	studentLine.push(stuSam);
	
	stuAuna.setMainCourse("Burger");
	studentLine.push(stuAuna);
	
	stuHind.setMainCourse("Pita Wrap");
	studentLine.push(stuHind);
	
	stuPaulina.setMainCourse("Enchilada de Pollo");
	studentLine.push(stuPaulina);
	
	stuVinny.setMainCourse("Cheese Soup");
	studentLine.push(stuVinny);
	
	while(!studentLine.empty()){
		
		std::cout << studentLine.front() << std::endl;
		
		std::cout << "Restaurat gives one " << studentLine.front().getMainCourse() << " ";
		std::cout << "to " << studentLine.front().getName() << std::endl;
		
		studentLine.pop();
		std::cout << std::endl;
	}
	
}