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


# Create the Fact Double Sci Run
fact_double_sci.o: fact_double_sci.c
	$(CC) $(CFLAGS) -c fact_double_sci.c

# Parallel Program Objects
fact_double_sci_objs := fact_double_sci.o 

#Executables
fact_double_sci: $(fact_double_sci_objs)
	$(CC) $(CFLAGS) -o fact_double_sci $(fact_double_sci_objs)


# Create the Bird Lib Library
bird_lib.o: bird_lib.c
	$(CC) $(CFLAGS) -c bird_lib.c

# Create the Bird Run
bird_flap.o: bird_flap.c
	$(CC) $(CFLAGS) -c bird_flap.c

# Parallel Program Objects
bird_flap_objs := bird_lib.o bird_flap.o

#Executables
bird_flap: $(bird_flap_objs)
	$(CC) $(CFLAGS) -o bird_flap $(bird_flap_objs)

# Executable Names
executable_names := parallel_run fact_double_sci bird_flap

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
