# This is the Makefile for the Lecture 19 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)

# Build the main object
lec23.o: lec23.c
	$(CC) $(CFLAGS) -c lec23.c

# Build the sllist object
sllist.o: sllist.c
	$(CC) $(CFLAGS) -c sllist.c

# All Objects
sllist_objects := lec23.o sllist.o

# Compilation
sllist: $(sllist_objects)
	$(CC) $(CFLAGS) -o sllist $(sllist_objects) -lm

# All executables
executable_names := sllist

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
