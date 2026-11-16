# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 38 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

MATPLOT = -I/usr/local/include/matplot/ -lmatplot

# C++ Preprocessing and Visualization Introduction
# Command: make iris_visual
iris.o: iris.cpp
	$(PP) $(CXXFLAGS) -c iris.cpp $(MATPLOT)

# Contains the library for the 
preprocessing.o: preprocessing.cpp
	$(PP) $(CXXFLAGS) -c preprocessing.cpp $(MATPLOT)

# The main driver function
iris_visual.o: iris_visual.cpp
	$(PP) $(CXXFLAGS) -c iris_visual.cpp $(MATPLOT)

# Create the full objects list
iris_visual_objs := iris.o preprocessing.o iris_visual.o

# Generate the Makefile and run using the full valgrind
iris_visual: $(iris_visual_objs)
	$(PP) $(CXXFLAGS) -o iris_visual $(iris_visual_objs) $(MATPLOT) -lm
	valgrind --leak-check=full --track-origins=yes ./iris_visual iris.data

# Set the executable name
executable_names := iris_visual

# Make clean
clean :
	rm -rf *.o $(executable_names)
