# This is the Makefile for the CSE 20311 course - Lecture 35

# G++ is for the GPP compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror 
CXXFLAGS := -std=c++2a $(FLAGS) 

# Command: make pthread_1
# Prints a pthread address an int - Not initialized yet, so PQC not included
pthread_1.o: pthread_1.cpp
	$(PP) -std=c++2a -c pthread_1.cpp -lpthread

pthread_1Objs := pthread_1.o 

pthread_1: $(pthread_1Objs)
	$(PP) -std=c++2a -o pthread_1 $(pthread_1Objs) -lpthread
	./pthread_1
	
	
# Command: make pthread_2
# Prints an initialized pthread
pthread_2Objs := pthread_2.o 

pthread_2: $(pthread_2Objs)
	$(PP) $(CXXFLAGS) -o pthread_2 $(pthread_2Objs) -lpthread
	valgrind --leak-check=full --track-origins=yes ./pthread_2

pthread_2.o: pthread_2.cpp
	$(PP) $(CXXFLAGS) -c pthread_2.cpp


# Command: make pthread_3
# Prints an initialized pthread
pthread_3Objs := pthread_3.o 

pthread_3: $(pthread_3Objs)
	$(PP) $(CXXFLAGS) -o pthread_3 $(pthread_3Objs) -lpthread
	valgrind --leak-check=full --track-origins=yes ./pthread_3

pthread_3.o: pthread_3.cpp
	$(PP) $(CXXFLAGS) -c pthread_3.cpp -lpthread
	
	
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

executables := pthread_1 pthread_2 pthread_3 pthread_in_class pthread_in_class_rc pthread_in_class_sol

# Make clean
clean :
	rm -rf *.o $(executables)
