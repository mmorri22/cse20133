# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 12 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)



# Create the maze Object
maze.o: maze.c
	$(CC) $(CFLAGS) -c maze.c

# Float Compile Objects
maze_objs := maze.o

# Float Compile Executable
maze: $(maze_objs)
	$(CC) $(CFLAGS) -o maze $(maze_objs)
	./maze


# Create the maze_demo Object
maze_demo.o: maze_demo.c
	$(CC) $(CFLAGS) -c maze_demo.c

# Float Compile Objects
maze_demo_objs := maze_demo.o

# Float Compile Executable
maze_demo: $(maze_demo_objs)
	$(CC) $(CFLAGS) -o maze_demo $(maze_demo_objs)
	./maze_demo


# Executable Names
executable_names := maze maze_demo

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
