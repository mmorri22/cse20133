# This is the Makefile for the CSE 20133 - Lab 12

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Command: make vector
vectorObjs := vector.o LIS.o

vector: $(vectorObjs)
	$(PP) $(CXXFLAGS) -o vector $(vectorObjs)

vector.o: vector.cpp
	$(PP) $(CXXFLAGS) -c vector.cpp


# Command: make Lab12
Lab12Objs := Lab12.o LIS.o

Lab12: $(Lab12Objs)
	$(PP) $(CXXFLAGS) -o Lab12 $(Lab12Objs)

Lab12.o: Lab12.cpp LIS.h
	$(PP) $(CXXFLAGS) -c Lab12.cpp

LIS.o: LIS.cpp LIS.h
	$(PP) $(CXXFLAGS) -c LIS.cpp	

# Make all
all: Lab12 


# Make clean
clean :
	rm -rf *.o Lab12
