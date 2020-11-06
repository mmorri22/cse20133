# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 39

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)



# namespace Example
# Command: make namespace
namespaceObjs :=  namespace.o

namespace: namespace.o
	$(PP) $(PQCXX) -o namespace $(namespaceObjs)
	./namespace

namespace.o: namespace.cpp
	$(PP) $(PQCXX) -c namespace.cpp
	
	
	
# nameGood Example
# Command: make nameGood
nameGoodObjs :=  nameGood.o

nameGood: nameGood.o
	$(PP) $(PQCXX) -o nameGood $(nameGoodObjs)
	./nameGood

nameGood.o: nameGood.cpp
	$(PP) $(PQCXX) -c nameGood.cpp


# nameGood2 Example
# Command: make nameGood2
nameGood2Objs :=  nameGood2.o

nameGood2: nameGood2.o
	$(PP) $(PQCXX) -o nameGood2 $(nameGood2Objs)
	./nameGood2

nameGood2.o: nameGood2.cpp
	$(PP) $(PQCXX) -c nameGood2.cpp




# Towers of Hanoi Example
# Command: make hanoi
hanoiObjs :=  hanoi.o

hanoi: hanoi.o
	$(PP) $(PQCXX) -o hanoi $(hanoiObjs)

hanoi.o: hanoi.cpp Tower.h
	$(PP) $(PQCXX) -c hanoi.cpp	
	

# Make all
all: namespace nameGood nameGood2 hanoi
 
# Make clean
clean :
	rm -rf *.o namespace nameGood nameGood2 hanoi
