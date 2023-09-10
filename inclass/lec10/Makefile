# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 10 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)


# Create the Static Basic Object
static_basic.o: static_basic.c
	$(CC) $(CFLAGS) -c static_basic.c

# Trace Objects
static_basic_objs := static_basic.o

# Trace Executable and Run
static_basic: $(static_basic_objs)
	$(CC) $(CFLAGS) -o ptr_trace $(static_basic_objs)
	./static_basic


# Create the Static Basic Pass By Reference Object
static_pbr.o: static_pbr.c
	$(CC) $(CFLAGS) -c static_pbr.c

# Static Basic Objects
static_pbr_objs := static_pbr.o

# Trace Executable and Run
static_pbr: $(static_pbr_objs)
	$(CC) $(CFLAGS) -o static_pbr $(static_pbr_objs)
	./static_pbr



# Create the Insertion Sort Object
insertion_sort.o: insertion_sort.c
	$(CC) $(CFLAGS) -c insertion_sort.c

# Float Compile Objects
insertion_sort_objs := insertion_sort.o

# Float Compile Executable
insertion_sort: $(insertion_sort_objs)
	$(CC) $(CFLAGS) -o insertion_sort $(insertion_sort_objs)
	./insertion_sort



# Executable Names
executable_names := static_basic static_pbr insertion_sort

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
