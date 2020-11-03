# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 02 - Part 2

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


# quadPair Example - std::pair
# Command: make quadPair
quadPairObjs :=  quadPair.o

quadPair: quadPair.o
	$(PP) $(PQCXX) -o quadPair $(quadPairObjs)
	./quadPair

quadPair.o: quadPair.cpp
	$(PP) $(PQCXX) -c quadPair.cpp	



# quadPair2 Example - std::pair
# Command: make quadPair2
quadPair2Objs :=  quadPair2.o

quadPair2: quadPair2.o
	$(PP) $(PQCXX) -o quadPair2 $(quadPair2Objs)
	./quadPair2

quadPair2.o: quadPair2.cpp
	$(PP) $(PQCXX) -c quadPair2.cpp		



# fwdList Example - Singly Linked List
# Command: make fwdList
fwdListObjs :=  fwdList.o

fwdList: fwdList.o
	$(PP) $(PQCXX) -o fwdList $(fwdListObjs)
	./fwdList

fwdList.o: fwdList.cpp
	$(PP) $(PQCXX) -c fwdList.cpp
	
	
	
# Iterator Example
# Command: make iterator
iteratorObjs :=  iterator.o

iterator: iterator.o
	$(PP) $(PQCXX) -o iterator $(iteratorObjs)
	./iterator

iterator.o: iterator.cpp
	$(PP) $(PQCXX) -c iterator.cpp		


# Doubly Linked List Example
# Command: make inigo
inigoObjs :=  inigo.o

inigo: inigo.o
	$(PP) $(PQCXX) -o inigo $(inigoObjs)
	./inigo

inigo.o: inigo.cpp
	$(PP) $(PQCXX) -c inigo.cpp	
	


# Stack Example
# Command: make stackTest
stackTestObjs :=  stackTest.o

stackTest: stackTest.o
	$(PP) $(PQCXX) -o stackTest $(stackTestObjs)

stackTest.o: stackTest.cpp
	$(PP) $(PQCXX) -c stackTest.cpp		



# Towers of Hanoi Example
# Command: make hanoi
hanoiObjs :=  hanoi.o

hanoi: hanoi.o
	$(PP) $(PQCXX) -o hanoi $(hanoiObjs)

hanoi.o: hanoi.cpp Tower.h
	$(PP) $(PQCXX) -c hanoi.cpp	
	

# Make all
all: quadPair quadPair2 fwdList iterator inigo stackTest hanoi
 
# Make clean
clean :
	rm -rf *.o quadPair quadPair2 fwdList inigo iterator stackTest hanoi
