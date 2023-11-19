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

# C++ Visualization Introduction
# Command: make minimal
# We will fix $(MATPLOT) here
minimal.o: minimal.cpp
	$(PP) $(CXXFLAGS) -c minimal.cpp $(MATPLOT)

minimal_objs := minimal.o

minimal: $(minimal_objs)
	$(PP) $(CXXFLAGS) -o minimal $(minimal_objs) $(MATPLOT) -lm


# C++ Visualization Introduction
# Command: make 3d_plot
3d_plot.o: 3d_plot.cpp
	$(PP) $(CXXFLAGS) -c 3d_plot.cpp $(MATPLOT)

3d_plot_objs := 3d_plot.o

3d_plot: $(3d_plot_objs)
	$(PP) $(CXXFLAGS) -o 3d_plot $(3d_plot_objs) $(MATPLOT) -lm


# C++ Visualization - Multiple Plots
# Command: make sin_cos
sin_cos.o: sin_cos.cpp
	$(PP) $(CXXFLAGS) -c sin_cos.cpp $(MATPLOT)

sin_cos_objs := sin_cos.o

sin_cos: $(sin_cos_objs)
	$(PP) $(CXXFLAGS) -o sin_cos $(sin_cos_objs) $(MATPLOT) -lm

executable_names := 3d_plot sin_cos minimal

# Make clean
clean :
	rm -rf *.o $(executable_names)
