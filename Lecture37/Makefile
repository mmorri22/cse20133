# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the CSE 20133 - Lecture 36

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)


# Command: make NDFightSongFSM
NDFightSongFSMObjs := NDFightSongFSM.o

NDFightSongFSM: $(NDFightSongFSMObjs)
	$(PP) $(CXXFLAGS) -o NDFightSongFSM $(NDFightSongFSMObjs)

NDFightSongFSM.o: NDFightSongFSM.cpp
	$(PP) $(CXXFLAGS) -c NDFightSongFSM.cpp -o $@


# Command: make Moore
MooreObjs := Moore.o

Moore: $(MooreObjs)
	$(PP) $(CXXFLAGS) -o Moore $(MooreObjs)

Moore.o: Moore.cpp
	$(PP) $(CXXFLAGS) -c Moore.cpp -o $@
	


# Make all
all: NDFightSongFSM Moore


# make initialize
# Will be called by grader to initialize your objects and executables folders

initialize: 
	mkdir objects executables

# Make clean
clean :
	rm -rf *.o NDFightSongFSM Moore
