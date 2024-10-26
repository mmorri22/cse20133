# This is the Makefile for the Lecture 21 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Build the main object
lec22.o: lec22.c
	$(CC) $(CFLAGS) -c lec22.c

# All Objects
library_objects := lec22.o

# Compilation
library: $(library_objects)
	$(CC) $(CFLAGS) -o library $(library_objects) -lm

# All executables
executable_names := library

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)