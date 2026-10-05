# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 18 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)


# Create the Double Object
double.o: double.c
	$(CC) $(CFLAGS) -c double.c

# Static Dynamic Function Objects
double_objs := double.o

# Static Dynamic Function Executable
double: $(double_objs)
	$(CC) $(CFLAGS) -o double $(double_objs)
	./double


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
dyn_array_reg.o: dyn_array_reg.c
	$(CC) $(CFLAGS) -c dyn_array_reg.c

# Dynamic Array Run Time Objects
dyn_array_reg_objs := dyn_array_time.o

# Dynamic Array Run Time Executable
dyn_array_reg: $(dyn_array_reg_objs)
	$(CC) $(CFLAGS) -o dyn_array_reg $(dyn_array_reg_objs)
	./dyn_array_reg


# Inefficient Dynamic Array Compilation
dyn_array_ineff:
	gcc dyn_array.c -o dyn_array_ineff
	./dyn_array_ineff

# Simple Stat Array Compiler that is *not* optimized
stat_array_ineff:
	gcc stat_array.c -o stat_array_ineff
	./stat_array_ineff

# Simple Stat Array Compiler that is *not* optimized
stat_array_reg_ineff:
	gcc stat_array_reg.c -o stat_array_reg_ineff
	./stat_array_reg_ineff



# Make Time Comparisons
time_comp: clean dyn_array_reg stat_array_ineff stat_array_reg_ineff dyn_array_ineff


# Executable Names
executable_names := stat_dyn_func dyn_array_reg stat_array_ineff stat_array_reg_ineff dyn_array_ineff double

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)