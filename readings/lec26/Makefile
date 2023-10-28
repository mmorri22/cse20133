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
	$(PP) $(CXXFLAGS) -c new_delete.cpp -o 
	
new_delete_objs := new_delete.o

new_delete: $(new_delete_objs)
	$(PP) $(CXXFLAGS) -o new_delete $(new_delete_objs) -lm
	
	
# C++ Call by Reference Example
# Command: make pass_call_comp
pass_call_comp.o: pass_call_comp.cpp
	$(PP) $(CXXFLAGS) -c pass_call_comp.cpp -o 
	
pass_call_comp_objs := pass_call_comp.o

pass_call_comp: $(pass_call_comp_objs)
	$(PP) $(CXXFLAGS) -o pass_call_comp $(pass_call_comp_objs) -lm
	
	
# C++ Templates Example
# Command: make template
template.o: template.cpp
	$(PP) $(CXXFLAGS) -c template.cpp -o 
	
template_objs := template.o

template: $(template_objs)
	$(PP) $(CXXFLAGS) -o template $(template_objs) -lm
	
	
# C++ Vector Example
# Command: make vector
vector.o: vector.cpp
	$(PP) $(CXXFLAGS) -c vector.cpp -o 
	
vector_objs := vector.o

vector: $(vector_objs)
	$(PP) $(CXXFLAGS) -o vector $(vector_objs) -lm
	
	
# C++ Vector Capacity Example
# Command: make vector_capac
vector_capac.o: vector_capac.cpp
	$(PP) $(CXXFLAGS) -c vector_capac.cpp -o 
	
vector_capac_objs := vector_capac.o

vector_capac: $(vector_capac_objs)
	$(PP) $(CXXFLAGS) -o vector_capac $(vector_capac_objs) -lm

executable_names := hello_cpp
	
# Make clean
clean :
	rm -rf *.o $(executable_names)