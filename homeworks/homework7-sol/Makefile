# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Homework 07 - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

# C++ product example
# Command: make product
homework07.o: homework07.cpp
	$(PP) $(CXXFLAGS) -c homework07.cpp

palindrome.o: palindrome.cpp
	$(PP) $(CXXFLAGS) -c palindrome.cpp

homework07_objs := homework07.o palindrome.cpp

homework07: $(homework07_objs)
	$(PP) $(CXXFLAGS) -o homework07 $(homework07_objs) -lm

executable_names := homework07

# Make clean
clean :
	rm -rf *.o $(executable_names)
