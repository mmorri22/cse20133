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


# C++ Visualization Introduction
# Command: make minimal

#### Update all .o and executable with $(MATPLOT) after .cpp and objs
minimal.o: minimal.cpp
	$(PP) $(CXXFLAGS) -c minimal.cpp

minimal_objs := minimal.o

minimal: $(minimal_objs)
	$(PP) $(CXXFLAGS) -o minimal $(minimal_objs) -lm


# C++ Visualization Introduction
# Command: make 3d_plot
3d_plot.o: 3d_plot.cpp
	$(PP) $(CXXFLAGS) -c 3d_plot.cpp $(MATPLOT)

3d_plot_objs := 3d_plot.o

3d_plot: $(3d_plot_objs)
	$(PP) $(CXXFLAGS) -o 3d_plot $(3d_plot_objs) $(MATPLOT) -lm


executable_names := 3d_plot minimal

# Make clean
clean :
	rm -rf *.o $(executable_names)
