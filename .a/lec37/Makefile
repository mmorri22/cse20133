# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 32 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

# Update with our final flag of the semester: MATPLOT
# MATPLOT = -I/usr/local/include/matplot/ -lmatplot
MATPLOT = -I/usr/local/include/matplot/ -lmatplot



# C++ Visualization - Multiple Plots
# Command: make sin_cos
sin_cos.o: sin_cos.cpp
	$(PP) $(CXXFLAGS) -c sin_cos.cpp $(MATPLOT)

sin_cos_objs := sin_cos.o

sin_cos: $(sin_cos_objs)
	$(PP) $(CXXFLAGS) -o sin_cos $(sin_cos_objs) $(MATPLOT) -lm



# C++ Visualization - Electric Field
# Command: make electric
electric.o: electric.cpp
	$(PP) $(CXXFLAGS) -c electric.cpp $(MATPLOT)

electric_objs := electric.o

electric: $(electric_objs)
	$(PP) $(CXXFLAGS) -o electric $(electric_objs) $(MATPLOT) -lm

executable_names := sin_cos scatter electric

# Make clean
clean :
	rm -rf *.o $(executable_names)
