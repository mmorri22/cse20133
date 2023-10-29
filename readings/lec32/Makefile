# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 32 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -m64 -std=c++2a $(FLAGS)


# C++ Class with Data Preprocessing and Visualization
# Command: make iris
preprocessing.o: preprocessing.cpp
	$(PP) $(CXXFLAGS) -c preprocessing.cpp

iris_prepr.o: iris_prepr.cpp
	$(PP) $(CXXFLAGS) -c iris_prepr.cpp

iris_prepr_objs := preprocessing.o iris_prepr.o

iris_prepr: $(iris_prepr_objs)
	$(PP) $(CXXFLAGS) -o iris_prepr $(iris_prepr_objs) -lm

executable_names := iris_prepr
	
# Make clean
clean :
	rm -rf *.o $(executable_names)