# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 13 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Create the Better Malloc Object
maze_demo.o: maze_demo.c
	$(CC) $(CFLAGS) -c maze_demo.c

# Better Malloc Objects
maze_demo_objs := maze_demo.o

# Better Malloc Executable
maze_demo: $(maze_demo_objs)
	$(CC) $(CFLAGS) -o maze_demo $(maze_demo_objs)
	valgrind --leak-check=full ./maze_demo -lm


# Create the Maze Object
maze.o: maze.c
	$(CC) $(CFLAGS) -c maze.c

# Better Malloc Objects
maze_objs := maze.o

# Better Malloc Executable
maze: $(maze_objs)
	$(CC) $(CFLAGS) -o maze $(maze_objs)
	valgrind --leak-check=full ./maze -lm


# Executable Names
executable_names := maze_demo maze

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
