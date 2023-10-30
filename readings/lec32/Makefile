# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 32 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

# Note, after installation, I ran the commands and got the following:
# Command: python3 --version
# Result : Python 3.8.10
PY_INCLUDES = -I/usr/include/python3.8 -lpython3.8

# C++ Class with Data Preprocessing and Visualization
# Command: make iris
preprocessing.o: preprocessing.cpp
	$(PP) $(CXXFLAGS) -c preprocessing.cpp

iris_prepr.o: iris_prepr.cpp
	$(PP) $(CXXFLAGS) -c iris_prepr.cpp

iris_prepr_objs := preprocessing.o iris_prepr.o

iris_prepr: $(iris_prepr_objs)
	$(PP) $(CXXFLAGS) -o iris_prepr $(iris_prepr_objs) -lm


# C++ Visualization Introduction
# Command: make minimal
minimal.o: minimal.cpp
	$(PP) $(CXXFLAGS) -c minimal.cpp $(PY_INCLUDES)

minimal_objs := minimal.o

minimal: $(minimal_objs)
	$(PP) $(CXXFLAGS) -o minimal $(minimal_objs) $(PY_INCLUDES) -lm


# C++ Preprocessing and Visualization Introduction
# Command: make iris_visual
iris_visual.o: iris_visual.cpp
	$(PP) $(CXXFLAGS) -c iris_visual.cpp $(PY_INCLUDES)

iris_visual_objs := preprocessing.o iris_visual.o

iris_visual: $(iris_visual_objs)
	$(PP) $(CXXFLAGS) -o iris_visual $(iris_visual_objs) $(PY_INCLUDES) -lm

executable_names := iris_prepr minimal iris_visual

# Make clean
clean :
	rm -rf *.o $(executable_names)
