# Author: Prof. Morrison
# E-mail: mmorri22@nd.edu
#
# This is the Makefile for the Lecture 8 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CFLAGS := -std=c2x $(FLAGS)

# Create the Pallel Lib Library
parallel_lib.o: parallel_lib.c
	$(CC) $(CFLAGS) -c parallel_lib.c

# Create the Pallel Run
parallel_run.o: parallel_run.c
	$(CC) $(CFLAGS) -c parallel_run.c

# Parallel Program Objects
parallel_objs := parallel_lib.o parallel_run.o

#Executables
parallel_run: $(parallel_objs)
	$(CC) $(CFLAGS) -o parallel_run $(parallel_objs)
	./parallel_run


# fact_lib object file
fact_lib.o: fact_lib.c
	$(CC) $(CFLAGS) -c fact_lib.c

fact_run.o: fact_run.c
	$(CC) $(CFLAGS) -c fact_run.c

# Object File List
fact_run_objs := fact_lib.o fact_run.o

# fact_run executable
fact_run: $(fact_run_objs)
	$(CC) $(CFLAGS) -o fact_run $(fact_run_objs)
	./fact_run

# Executable Names
executable_names := parallel_run fact_run

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names) 
