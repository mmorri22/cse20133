# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 5 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)


# Create the Trace Object
ptr_trace.o: ptr_trace.c
	$(CC) $(CFLAGS) -c ptr_trace.c

# Trace Objects
ptr_trace_objs := ptr_trace.o

# Trace Executable and Run
ptr_trace: $(ptr_trace_objs)
	$(CC) $(CFLAGS) -o ptr_trace $(ptr_trace_objs)
	./ptr_trace


# Create the Trace Object Pass By Reference
ptr_trace_pbr.o: ptr_trace_pbr.c
	$(CC) $(CFLAGS) -c ptr_trace_pbr.c

# Trace Objects
ptr_trace_pbr_objs := ptr_trace_pbr.o

# Trace Executable and Run
ptr_trace_pbr: $(ptr_trace_pbr_objs)
	$(CC) $(CFLAGS) -o ptr_trace_pbr $(ptr_trace_pbr_objs)
	./ptr_trace_pbr


# Create the fscanf Object
fscanf.o: fscanf.c
	$(CC) $(CFLAGS) -c fscanf.c

# Float Compile Objects
fscanf_objs := fscanf.o

# Float Compile Executable
fscanf: $(fscanf_objs)
	$(CC) $(CFLAGS) -o fscanf $(fscanf_objs)
	./fscanf


# Create the fscanf_pbr Object
fscanf_pbr.o: fscanf_pbr.c
	$(CC) $(CFLAGS) -c fscanf_pbr.c

# Float Compile Objects
fscanf_pbr_objs := fscanf_pbr.o

# Float Compile Executable
fscanf_pbr: $(fscanf_pbr_objs)
	$(CC) $(CFLAGS) -o fscanf_pbr $(fscanf_pbr_objs)
	./fscanf_pbr


# Executable Names
executable_names := ptr_trace fscanf_pbr fscanf ptr_trace_pbr

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
