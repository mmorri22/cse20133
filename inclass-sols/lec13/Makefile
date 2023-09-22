# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 7 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Create the Void Recast Object
void_recast.o: void_recast.c
	$(CC) $(CFLAGS) -c void_recast.c

# Void Recast Compile Objects
void_recast_objs := void_recast.o

# Void Recast Compile Executable
void_recast: $(void_recast_objs)
	$(CC) $(CFLAGS) -o void_recast $(void_recast_objs) -lm
	valgrind --leak-check=full ./void_recast


# Executable Names
executable_names := void_recast

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
