# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 28 In-Class - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

# C++ Prob1 example
# Command: make product
Prob1.o: Prob1.cpp
	$(PP) $(CXXFLAGS) -c Prob1.cpp

Prob1_objs := Prob1.o

Prob1: $(Prob1_objs)
	$(PP) $(CXXFLAGS) -o Prob1 $(Prob1_objs) -lm
	./Prob1


# C++ Prob2 example
# Command: make product
Prob2.o: Prob2.cpp
	$(PP) $(CXXFLAGS) -c Prob2.cpp

Prob2_objs := Prob2.o

Prob2: $(Prob2_objs)
	$(PP) $(CXXFLAGS) -o Prob2 $(Prob2_objs) -lm
	./Prob2


# C++ Prob3 example
# Command: make product
Prob3.o: Prob3.cpp
	$(PP) $(CXXFLAGS) -c Prob3.cpp

Prob3_objs := Prob3.o

Prob3: $(Prob3_objs)
	$(PP) $(CXXFLAGS) -o Prob3 $(Prob3_objs) -lm
	./Prob3


# C++ Prob4 example
# Command: make product
Prob4.o: Prob4.cpp
	$(PP) $(CXXFLAGS) -c Prob4.cpp

Prob4_objs := Prob4.o

Prob4: $(Prob4_objs)
	$(PP) $(CXXFLAGS) -o Prob4 $(Prob4_objs) -lm
	./Prob4


# C++ Prob5 example
# Command: make product
Prob5.o: Prob5.cpp
	$(PP) $(CXXFLAGS) -c Prob5.cpp

Prob5_objs := Prob5.o

Prob5: $(Prob5_objs)
	$(PP) $(CXXFLAGS) -o Prob5 $(Prob5_objs) -lm
	./Prob5


# C++ Prob6 example
# Command: make product
Prob6.o: Prob6.cpp
	$(PP) $(CXXFLAGS) -c Prob6.cpp

Prob6_objs := Prob6.o

Prob6: $(Prob6_objs)
	$(PP) $(CXXFLAGS) -o Prob6 $(Prob6_objs) -lm
	./Prob6

# C++ Prob7 example
# Command: make product
Prob7.o: Prob7.cpp
	$(PP) $(CXXFLAGS) -c Prob7.cpp

Prob7_objs := Prob7.o

Prob7: $(Prob7_objs)
	$(PP) $(CXXFLAGS) -o Prob7 $(Prob7_objs) -lm
	./Prob7


# C++ Prob8 example
# Command: make product
Prob8.o: Prob8.cpp
	$(PP) $(CXXFLAGS) -c Prob8.cpp

Prob8_objs := Prob8.o

Prob8: $(Prob8_objs)
	$(PP) $(CXXFLAGS) -o Prob8 $(Prob8_objs) -lm
	./Prob8


# C++ Prob9 example
# Command: make product
Prob9.o: Prob9.cpp
	$(PP) $(CXXFLAGS) -c Prob9.cpp

Prob9_objs := Prob9.o

Prob9: $(Prob9_objs)
	$(PP) $(CXXFLAGS) -o Prob9 $(Prob9_objs) -lm
	./Prob9


executable_names := Prob1 Prob2 Prob3 Prob4 Prob5 Prob6 Prob7 Prob8 Prob9

all: $(executable_names)

# Make clean
clean :
	rm -rf *.o $(executable_names)
