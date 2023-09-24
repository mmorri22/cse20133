# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 19 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Create the Better Malloc Object
filePtrExBad.o: filePtrExBad.c
	$(CC) $(CFLAGS) -c filePtrExBad.c

# Better Malloc Objects
filePtrExBad_objs := filePtrExBad.o

# Better Malloc Executable
filePtrExBad: $(filePtrExBad_objs)
	$(CC) $(CFLAGS) -o filePtrExBad $(filePtrExBad_objs) -lm
	valgrind --leak-check=full ./filePtrExBad


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
