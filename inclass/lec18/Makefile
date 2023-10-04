# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 13 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)

# Create the Better Malloc Object
structs.o: structs.c
	$(CC) $(CFLAGS) -c structs.c

# Better Malloc Objects
structs_objs := structs.o

# Better Malloc Executable
structs: $(structs_objs)
	$(CC) $(CFLAGS) -o structs $(structs_objs)


# Create the mem_map Object
mem_map.o: mem_map.c
	$(CC) $(CFLAGS) -c mem_map.c

# Better Malloc Objects
mem_map_objs := mem_map.o

# Better Malloc Executable
mem_map: $(mem_map_objs)
	$(CC) $(CFLAGS) -o mem_map $(mem_map_objs)


# Executable Names
executable_names := structs mem_map

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
