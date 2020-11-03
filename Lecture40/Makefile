# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20133 course Lecture 34

# GCC is for the GCC compiler for C
CC := gcc

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CFLAGS := -std=c11 $(FLAGS)
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS) 



# Command: make HW09
# Upconter solution
HW09Objs :=  HW09.o DFF.o

HW09: $(HW09Objs)
	$(PP) $(CXXFLAGS) -o HW09 $(HW09Objs)

HW09.o: HW09.cpp DFF.h
	$(PP) $(CXXFLAGS) -c HW09.cpp

DFF.o: DFF.cpp DFF.h
	$(PP) $(CXXFLAGS) -c DFF.cpp
	

# Make all
all: HW09

# Make clean
clean :
	rm -rf *.o HW09
