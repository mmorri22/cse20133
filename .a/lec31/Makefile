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


# class_intro Example
# Command: make class_intro 
class_intro.o: class_intro.cpp
	$(PP) $(CXXFLAGS) -c class_intro.cpp

class_intro_objs := class_intro.o point.o

class_intro: $(class_intro_objs)
	$(PP) $(CXXFLAGS) -o class_intro $(class_intro_objs)
	./class_intro


# aggregate Example
# Command: make aggregate 
aggregate.o: aggregate.cpp
	$(PP) $(CXXFLAGS) -c aggregate.cpp

aggregate_objs := aggregate.o line.o point.o

aggregate: $(aggregate_objs)
	$(PP) $(CXXFLAGS) -o aggregate $(aggregate_objs)
	./aggregate


# Make all
executables := class_intro aggregate

# Make clean
clean :
	rm -rf *.o $(executables)