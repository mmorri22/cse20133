# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 7 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)

# Create the Pallel Lib Library
parallel_lib.o: parallel_lib.c
	$(CC) $(CFLAGS) -c parallel_lib.c

# Create the Pallel Run
parallel_run.o: parallel_run.c
	$(CC) $(CFLAGS) -c parallel_run.c

# Parallel Program Objects
parallel_objs := parallel_run.o parallel_lib.o

#Executables
parallel_run: $(parallel_objs)
	$(CC) $(CFLAGS) -o parallel_run $(parallel_objs)

# Executable Names
executable_names := parallel_run

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
