# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 32 Reading - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)

MATPLOT = -I/usr/local/include/matplot/ -lmatplot

# C++ Visualization Introduction
# Command: make minimal
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


# C++ Class with Data Preprocessing and Visualization
# Command: make iris
preprocessing.o: preprocessing.cpp
	$(PP) $(CXXFLAGS) -c preprocessing.cpp

iris_prepr.o: iris_prepr.cpp
	$(PP) $(CXXFLAGS) -c iris_prepr.cpp

iris_prepr_objs := preprocessing.o iris_prepr.o

iris_prepr: $(iris_prepr_objs)
	$(PP) $(CXXFLAGS) -o iris_prepr $(iris_prepr_objs) -lm



# C++ Preprocessing and Visualization Introduction
# Command: make iris_visual
iris_visual.o: iris_visual.cpp
	$(PP) $(CXXFLAGS) -c iris_visual.cpp $(MATPLOT)

iris_visual_objs := preprocessing.o iris_visual.o

iris_visual: $(iris_visual_objs)
	$(PP) $(CXXFLAGS) -o iris_visual $(iris_visual_objs) $(MATPLOT) -lm

executable_names := 3d_plot iris_prepr minimal iris_visual

# Make clean
clean :
	rm -rf *.o $(executable_names)
