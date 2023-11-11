# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 31

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CXXFLAGS := -std=c++2a $(FLAGS)


# Point Class Compilation:
point.o: point.cpp
	$(PP) $(CXXFLAGS) -c point.cpp


# Line Class Compilation:
line.o: line.cpp
	$(PP) $(CXXFLAGS) -c line.cpp


# aggregate Example
# Command: make aggregate 
aggregate.o: aggregate.cpp
	$(PP) $(CXXFLAGS) -c aggregate.cpp

aggregate_objs := aggregate.o line.o point.o

aggregate: $(aggregate_objs)
	$(PP) $(CXXFLAGS) -o aggregate $(aggregate_objs)
	./aggregate


# Fractals Example
# Command: make fractals 
fractals.o: fractals.cpp
	$(PP) $(CXXFLAGS) -c fractals.cpp

fractal_lib.o: fractal_lib.cpp
	$(PP) $(CXXFLAGS) -c fractal_lib.cpp

gfx.o: gfx.cpp
	$(PP) $(CXXFLAGS) -c gfx.cpp

fractals_objs := fractals.o fractal_lib.o gfx.o

fractals: $(fractals_objs)
	$(PP) $(CXXFLAGS) -o fractals $(fractals_objs) -lX11

# Make all
executables := aggregate fractals

# Make clean
clean :
	rm -rf *.o $(executables)