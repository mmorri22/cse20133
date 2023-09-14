# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 10 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)


# Create the Static Basic Object
static_basic.o: static_basic.c
	$(CC) $(CFLAGS) -c static_basic.c

# Trace Objects
static_basic_objs := static_basic.o

# Trace Executable and Run
static_basic: $(static_basic_objs)
	$(CC) $(CFLAGS) -o static_basic $(static_basic_objs) -lm
	./static_basic


# Create the Static Basic Pass By Reference Object
static_pbr.o: static_pbr.c
	$(CC) $(CFLAGS) -c static_pbr.c

# Static Basic Objects
static_pbr_objs := static_pbr.o

# Trace Executable and Run
static_pbr: $(static_pbr_objs)
	$(CC) $(CFLAGS) -o static_pbr $(static_pbr_objs) -lm
	./static_pbr


# Create the fscanf  Object
fscanf.o: fscanf.c
	$(CC) $(CFLAGS) -c fscanf.c

# Trace Objects
fscanf_objs := fscanf.o

# Trace Executable and Run
fscanf: $(fscanf_objs)
	$(CC) $(CFLAGS) -o fscanf $(fscanfc_objs) -lm
	./fscanf


# Create the Static Basic Pass By Reference Object
fscanf_pbr.o: fscanf_pbr.c
	$(CC) $(CFLAGS) -c fscanf_pbr.c

# Static Basic Objects
fscanf_pbr_objs := fscanf_pbr.o

# Trace Executable and Run
fscanf_pbr: $(fscanf_pbr_objs)
	$(CC) $(CFLAGS) -o fscanf_pbr $(fscanf_pbr_objs) -lm
	./fscanf_pbr


# Executable Names
executable_names := static_basic static_pbr fscanf fscanf_pbr

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
