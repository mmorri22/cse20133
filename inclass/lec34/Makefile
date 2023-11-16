# This is the Makefile for the CSE 20311 course - Lecture 34

# G++ is for the GPP compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror 
CXXFLAGS := -std=c++2a $(FLAGS) 
	
	
# Command: make pthread_in_class
# Prints an initialized pthread
pthread_in_classObjs := pthread_in_class.o 

pthread_in_class: $(pthread_in_classObjs)
	$(PP) $(CXXFLAGS) -o pthread_in_class $(pthread_in_classObjs) -lpthread
	valgrind --leak-check=full --track-origins=yes ./pthread_in_class

pthread_in_class.o: pthread_in_class.cpp
	$(PP) $(CXXFLAGS) -c pthread_in_class.cpp
	
	
# Command: make pthread_in_class_rc
# Prints an initialized pthread - No Mutex Lock
pthread_in_class_rcObjs := pthread_in_class_rc.o 

pthread_in_class_rc: $(pthread_in_class_rcObjs)
	$(PP) $(CXXFLAGS) -o pthread_in_class_rc $(pthread_in_class_rcObjs) -lpthread
	valgrind --leak-check=full --track-origins=yes ./pthread_in_class_rc

pthread_in_class_rc.o: pthread_in_class_rc.cpp
	$(PP) $(CXXFLAGS) -c pthread_in_class_rc.cpp


# Executables

executables := pthread_in_class pthread_in_class_rc pthread_in_class_sol

# Make clean
clean :
	rm -rf *.o $(executables)
