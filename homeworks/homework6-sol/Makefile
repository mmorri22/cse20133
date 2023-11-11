# This is the Makefile for the Lecture 19 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

##############################################
# Refer to this for your Homework 06 Makefile
##############################################

# Build the labrynth object
labrynth.o: labrynth.c
	$(CC) $(CFLAGS) -c labrynth.c

# Build the maze_generator library object
maze_generator.o: maze_generator.c
	$(CC) $(CFLAGS) -c maze_generator.c

# Build the homework06 object
homework06.o: homework06.c
	$(CC) $(CFLAGS) -c homework06.c

# All Objects
homework06_objects := homework06.o maze_generator.o labrynth.o

# Compilation
homework06: $(homework06_objects)
	$(CC) $(CFLAGS) -o homework06 $(homework06_objects) -lm

# All executables
executable_names := homework06

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
