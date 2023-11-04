# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 29 In-Class - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

# C++ product example
# Command: make product
product.o: product.cpp
	$(PP) $(CXXFLAGS) -c product.cpp

product_objs := product.o

product: $(product_objs)
	$(PP) $(CXXFLAGS) -o product $(product_objs) -lm


# C++ two_sums example
# Command: make two_sums
two_sums.o: two_sums.cpp
	$(PP) $(CXXFLAGS) -c two_sums.cpp

two_sums_objs := two_sums.o

two_sums: $(two_sums_objs)
	$(PP) $(CXXFLAGS) -o two_sums $(two_sums_objs) -lm


executable_names := product two_sums

# Make clean
clean :
	rm -rf *.o $(executable_names)
