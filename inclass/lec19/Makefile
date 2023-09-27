# This is the Makefile for the Lecture 19 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)

# Build the main object
lec19.o: lec19.c
	$(CC) $(CFLAGS) -c lec19.c

# Build the library object
library.o: library.c
	$(CC) $(CFLAGS) -c library.c

# All Objects
library_objects := lec19.o library.o

# Compilation
library: $(library_objects)
	$(CC) $(CFLAGS) -o library $(library_objects) -lm
	valgrind --leak-check=full ./library

# All executables
executable_names := library

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)