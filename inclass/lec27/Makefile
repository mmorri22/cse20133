# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 27 In-Class - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

# C++ vector example
# Command: make vector
vector.o: vector.cpp
	$(PP) $(CXXFLAGS) -c vector.cpp

vector_objs := vector.o

vector: $(vector_objs)
	$(PP) $(CXXFLAGS) -o vector $(vector_objs) -lm
	valgrind --leak-check=full ./vector


# C++ cin example
# Command: make cin
cin.o: cin.cpp
	$(PP) $(CXXFLAGS) -c cin.cpp

cin_objs := cin.o

cin: $(cin_objs)
	$(PP) $(CXXFLAGS) -o cin $(cin_objs) -lm
	./cin


# C++ File I/O Example
# Command: make file_io
file_io.o: file_io.cpp
	$(PP) $(CXXFLAGS) -c file_io.cpp

file_io_objs := file_io.o

file_io: $(file_io_objs)
	$(PP) $(CXXFLAGS) -o file_io $(file_io_objs) -lm


# C++ Class Example
# CONTAINS DELIBERATE COMPILER ERRORS
# SHOWS STUDENTS THE DRAWBACKS OF using namespace std;
# Command: make namespace
namespace.o: namespace.cpp
	$(PP) $(CXXFLAGS) -c namespace.cpp

namespace_objs := namespace.o

namespace: $(namespace_objs)
	$(PP) $(CXXFLAGS) -o namespace $(namespace_objs) -lm


# C++ Fixed Class Example
# Command: make namespace_fixed
namespace_fixed.o: namespace_fixed.cpp
	$(PP) $(CXXFLAGS) -c namespace_fixed.cpp

namespace_fixed_objs := namespace_fixed.o

namespace_fixed: $(namespace_fixed_objs)
	$(PP) $(CXXFLAGS) -o namespace_fixed $(namespace_fixed_objs) -lm
	./namespace_fixed


# C++ Call By Reference Example
# Command: make call_by
call_by.o: call_by.cpp
	$(PP) $(CXXFLAGS) -c call_by.cpp

call_by_objs := call_by.o

call_by: $(call_by_objs)
	$(PP) $(CXXFLAGS) -o call_by $(call_by_objs) -lm
	./call_by


executable_names := vector

# Make clean
clean :
	rm -rf *.o $(executable_names)
