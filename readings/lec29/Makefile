# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 29 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -m64 -std=c++2a $(FLAGS)


# C++ Class Example
# CONTAINS DELIBERATE COMPILER ERRORS
# SHOWS STUDENTS THE BENEFIT OF PRIVATE MEMBERS IN C++
# Command: make animal_bad
animal_bad.o: animal_bad.cpp
	$(PP) $(CXXFLAGS) -c animal_bad.cpp
	
animal_bad_objs := animal_bad.o

animal_bad: $(animal_bad_objs)
	$(PP) $(CXXFLAGS) -o animal_bad $(animal_bad_objs) -lm
	

# C++ Fixed Class Example
# Command: make animal_fixed
animal_fixed.o: animal_fixed.cpp
	$(PP) $(CXXFLAGS) -c animal_fixed.cpp
	
animal_fixed_objs := animal_fixed.o

animal_fixed: $(animal_fixed_objs)
	$(PP) $(CXXFLAGS) -o animal_fixed $(animal_fixed_objs) -lm


# C++ Class with Constructor and Destructor Example
# Command: make animal_class
animal_class.o: animal_class.cpp
	$(PP) $(CXXFLAGS) -c animal_class.cpp
	
animal_class_objs := animal_class.o

animal_class: $(animal_class_objs)
	$(PP) $(CXXFLAGS) -o animal_class $(animal_class_objs) -lm

executable_names := animal_bad animal_fixed animal_class
	
# Make clean
clean :
	rm -rf *.o $(executable_names)