# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 5 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Create the Hours Object
hours.o: hours.c
	$(CC) $(CFLAGS) -c hours.c

# Hours Objects
hours_objs := hours.o

# Hours Executable and Run
hours: $(hours_objs)
	$(CC) $(CFLAGS) -o hours $(hours_objs)
	./hours


# Create the Trace Object
ptr_trace.o: ptr_trace.c
	$(CC) $(CFLAGS) -c ptr_trace.c

# Trace Objects
ptr_trace_objs := ptr_trace.o

# Trace Executable and Run
ptr_trace: $(ptr_trace_objs)
	$(CC) $(CFLAGS) -o ptr_trace $(ptr_trace_objs)
	./ptr_trace


# Create the fscanf Object
fscanf.o: fscanf.c
	$(CC) $(CFLAGS) -c fscanf.c

# Float Compile Objects
fscanf_objs := fscanf.o

# Float Compile Executable
fscanf: $(fscanf_objs)
	$(CC) $(CFLAGS) -o fscanf $(fscanf_objs)
	./fscanf


# Create the Insert Sort Object
insert_sort.o: insert_sort.c
	$(CC) $(CFLAGS) -c insert_sort.c

# Float Compile Objects
insert_sort_objs := insert_sort.o

# Float Compile Executable
insert_sort: $(insert_sort_objs)
	$(CC) $(CFLAGS) -o insert_sort $(insert_sort_objs)
	./insert_sort


# Executable Names
executable_names := hours ptr_trace fscanf insert_sort

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
