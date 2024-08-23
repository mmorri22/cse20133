# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 7 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)

# Create the Square Library Object
square_lib.o: square_lib.c
	$(CC) $(CFLAGS) -c square_lib.c

# Create the Square Main Object
square.o: square.c
	$(CC) $(CFLAGS) -c square.c

# Square Program Objects
square_objs := square.o square_lib.o

# Square Executable
square: $(square_objs)
	$(CC) $(CFLAGS) -o square $(square_objs)
	./square

# Executable Names
executable_names := square

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
