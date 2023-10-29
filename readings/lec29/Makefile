# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 29 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CXXFLAGS := -m64 -std=c++2a $(FLAGS)


# C++ Hello, World Example
# Command: make hello
Animal.o: Animal.cpp
	$(PP) $(CXXFLAGS) -c Animal.cpp
	
Animal_objs := Animal.o

Animal: $(Animal_objs)
	$(PP) $(CXXFLAGS) -o Animal $(Animal_objs) -lm
	

# C++ New, Delete Example
# Command: make new_delete
new_delete.o: new_delete.cpp
	$(PP) $(CXXFLAGS) -c new_delete.cpp
	
new_delete_objs := new_delete.o

new_delete: $(new_delete_objs)
	$(PP) $(CXXFLAGS) -o new_delete $(new_delete_objs) -lm
	valgrind --leak-check=full ./new_delete
	
	
# C++ Call by Reference Example
# Command: make pass_call_comp
pass_call_comp.o: pass_call_comp.cpp
	$(PP) $(CXXFLAGS) -c pass_call_comp.cpp
	
pass_call_comp_objs := pass_call_comp.o

pass_call_comp: $(pass_call_comp_objs)
	$(PP) $(CXXFLAGS) -o pass_call_comp $(pass_call_comp_objs) -lm


# C++ Call by Reference Example
# Command: make alphabet_count
alphabet_count.o: alphabet_count.cpp
	$(PP) $(CXXFLAGS) -c alphabet_count.cpp
	
alphabet_count_objs := alphabet_count.o

alphabet_count: $(alphabet_count_objs)
	$(PP) $(CXXFLAGS) -o alphabet_count $(alphabet_count_objs) -lm

executable_names := Animal
	
# Make clean
clean :
	rm -rf *.o $(executable_names)