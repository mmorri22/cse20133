# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 18 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)


# Create the Static Dynamic Function Object
stat_dyn_func.o: stat_dyn_func.c
	$(CC) $(CFLAGS) -c stat_dyn_func.c

# Static Dynamic Function Objects
stat_dyn_func_objs := stat_dyn_func.o

# Static Dynamic Function Executable
stat_dyn_func: $(stat_dyn_func_objs)
	$(CC) $(CFLAGS) -o stat_dyn_func $(stat_dyn_func_objs)
	valgrind --leak-check=full ./stat_dyn_func


# Create the Dynamic Array Run Time Object
dyn_array_eff.o: dyn_array.c
	$(CC) $(CFLAGS) -c dyn_array.c -o dyn_array_eff.o

# Dynamic Array Run Time Objects
dyn_array_eff_objs := dyn_array_eff.o

dyn_array_eff: $(dyn_array_eff_objs)
	$(CC) $(CFLAGS) -o dyn_array_eff $(dyn_array_eff_objs)
	./dyn_array_eff
	@echo "----------------------------------------------"


# Inefficient Dynamic Array Compilation
dyn_array:
	gcc -std=c2x dyn_array.c -o dyn_array
	./dyn_array
	@echo "----------------------------------------------"

dyn_array_stat:
	gcc -std=c2x dyn_array_stat.c -o dyn_array_stat
	./dyn_array_stat
	@echo "----------------------------------------------"

dyn_array_reg:
	gcc -std=c2x dyn_array_reg.c -o dyn_array_reg
	./dyn_array_reg
	@echo "----------------------------------------------"

# Simple Stat Array Compiler that is *not* optimized
stat_array:
	gcc -std=c2x stat_array.c -o stat_array
	./stat_array
	@echo "----------------------------------------------"

# Simple Stat Array Compiler that is *not* optimized
stat_array_reg:
	gcc -std=c2x stat_array_reg.c -o stat_array_reg
	./stat_array_reg
	@echo "----------------------------------------------"

# Make Time Comparisons
time_comp: clean dyn_array dyn_array_stat dyn_array_reg stat_array stat_array_reg dyn_array_eff

# Executable Names
executable_names := stat_dyn_func dyn_array dyn_array_eff dyn_array_stat dyn_array_reg stat_array stat_array_reg

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
