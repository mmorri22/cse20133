# G++ is for the GPP compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS) 
	
# pizza Compilation:
pizza.o: pizza.cpp
	$(PP) $(CXXFLAGS) -c pizza.cpp -lpthread

homework09.o: homework09.cpp
	$(PP) $(CXXFLAGS) -c homework09.cpp -lpthread

# Command: make homework09
homework09_Objs := pizza.o homework09.o

homework09: $(homework09_Objs)
	$(PP) $(CXXFLAGS) -o homework09 $(homework09_Objs) -lpthread
	valgrind --leak-check=full --track-origins=yes ./homework09

# Executables

executables := homework09

# Make clean
clean :
	rm -rf *.o $(executables)
