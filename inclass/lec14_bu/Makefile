# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 14 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)


# Create the Static Dynamic Address Object
stat_dyn_addr.o: stat_dyn_addr.c
	$(CC) $(CFLAGS) -c stat_dyn_addr.c

# Static Dynamic Address Objects
stat_dyn_addr_objs := stat_dyn_addr.o

# Static Dynamic Address Executable
stat_dyn_addr: $(stat_dyn_addr_objs)
	$(CC) $(CFLAGS) -o stat_dyn_addr $(stat_dyn_addr_objs) -lm
	./stat_dyn_addr

# Modify Line above based on in-class using valgrind --leak-check=full

# Executable Names
executable_names := stat_dyn_addr

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
