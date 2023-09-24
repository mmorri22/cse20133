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
	valgrind --leak-check=full ./stat_dyn_addr


# Inefficient Dynamic Array Compilation
dyn_array_time:
	gcc dyn_array_time.c -o dyn_array_time
	./dyn_array_time

# Simple Stat Array Compiler that is *not* optimized
stat_array_time:
	gcc stat_array_time.c -o stat_array_time
	./stat_array_time

# Simple Stat Array Compiler that is *not* optimized
stat_reg_time:
	gcc stat_reg_time.c -o stat_reg_time
	./stat_reg_time


# Create the Dynamic Array Run Time Object
dyn_array_time_eff.o: dyn_array_time.c
	$(CC) $(CFLAGS) -c dyn_array_time.c

# Dynamic Array Run Time Objects
dyn_array_time_eff_objs := dyn_array_time_eff.o

# Dynamic Array Run Time Executable
dyn_array_time_eff: $(dyn_array_time_eff_objs)
	$(CC) $(CFLAGS) -o dyn_array_time_eff $(dyn_array_time_eff_objs) -lm
	./dyn_array_time_eff


# Executable Names
executable_names := stat_dyn_addr dyn_array_time stat_array_time stat_reg_time dyn_array_time_eff

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
