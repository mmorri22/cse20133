# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 26 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CXXFLAGS := -m64 -std=c++2a $(FLAGS)


# C++ Hello, World Example
# Command: make hello
hello_cpp.o: hello_cpp.cpp
	$(PP) $(CXXFLAGS) -c hello_cpp.cpp
	
hello_cpp_objs := hello_cpp.o

hello_cpp: $(hello_cpp_objs)
	$(PP) $(CXXFLAGS) -o hello_cpp $(hello_cpp_objs) -lm
	

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


executable_names := hello_cpp new_delete pass_call_comp
	
# Make clean
clean :
	rm -rf *.o $(executable_names)