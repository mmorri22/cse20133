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

# Variables for Folders
34 := ~/cse20133/34-AdvSTL


# Command: make hanoi
# Towers of Hanoi solution using 
# std::stack and recursion
hanoiObjs :=  $(34)/hanoi.o

hanoi: $(hanoiObjs)
	$(PP) $(CXXFLAGS) -o $(34)/hanoi $(hanoiObjs)

hanoi.o: $(34)/hanoi.cpp 
	$(PP) $(CXXFLAGS) -c $(34)/hanoi.cpp


# Command: make queueTest
# Towers of Hanoi solution using 
# std::stack and recursion
queueTestObjs :=  $(34)/queueTest.o $(34)/Student.o

queueTest: $(queueTestObjs)
	$(PP) $(CXXFLAGS) -o $(34)/queueTest $(queueTestObjs)

queueTest.o: $(34)/queueTest.cpp  $(34)Student.h
	$(PP) $(CXXFLAGS) -c $(34)/queueTest.cpp

Student.o: $(34)/Student.cpp  $(34)Student.h
	$(PP) $(CXXFLAGS) -c $(34)/Student.cpp
	
	
	
# Command: make treeTest
# Simple example of using Red-Black trees in C++ STL
# using std::set
treeTestObjs :=  $(34)/treeTest.o

treeTest: $(treeTestObjs)
	$(PP) $(CXXFLAGS) -o $(34)/treeTest $(treeTestObjs)

treeTest.o: $(34)/treeTest.cpp
	$(PP) $(CXXFLAGS) -c $(34)/treeTest.cpp


# Make all
all: hanoi queueTest treeTest

# Make clean
clean :
	rm -rf *.o hanoi queueTest treeTest
