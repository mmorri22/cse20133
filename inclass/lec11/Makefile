# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 7 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Create the Void Recast Object
void_recast.o: void_recast.c
	$(CC) $(CFLAGS) -c void_recast.c

# Float Compile Objects
void_recast_objs := void_recast.o

# Float Compile Executable
void_recast: $(void_recast_objs)
	$(CC) $(CFLAGS) -o void_recast $(void_recast_objs)
	valgrind --leak-check=full ./void_recast

# Create the Static Dynamic Address Object
stat_dyn_addr.o: stat_dyn_addr.c
	$(CC) $(CFLAGS) -c stat_dyn_addr.c

# Static Dynamic Address Objects
stat_dyn_addr_objs := stat_dyn_addr.o

# Static Dynamic Address Executable
stat_dyn_addr: $(stat_dyn_addr_objs)
	$(CC) $(CFLAGS) -o stat_dyn_addr $(stat_dyn_addr_objs)
	valgrind --leak-check=full ./stat_dyn_addr


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
dyn_array_time.o: dyn_array_time.c
	$(CC) $(CFLAGS) -c dyn_array_time.c

# Dynamic Array Run Time Objects
dyn_array_time_objs := dyn_array_time.o

# Dynamic Array Run Time Executable
dyn_array_time: $(dyn_array_time_objs)
	$(CC) $(CFLAGS) -o dyn_array_time $(dyn_array_time_objs)
	./dyn_array_time


# Inefficient Dynamic Array Compilation
dyn_array_time_ineff:
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


# Create the Line 1 Object
line1_ex.o: line1_ex.c
	$(CC) $(CFLAGS) -c line1_ex.c

# Line 1 Objects
line1_ex_objs := line1_ex.o

# Line 1 Run Time Executable
line1_ex: $(line1_ex_objs)
	$(CC) $(CFLAGS) -o line1_ex $(line1_ex_objs)
	./line1_ex


# Create the Line 2 Object
line2_ex.o: line2_ex.c
	$(CC) $(CFLAGS) -c line2_ex.c

# Line 2 Objects
line2_ex_objs := line2_ex.o

# Line 2 Run Time Executable
line2_ex: $(line2_ex_objs)
	$(CC) $(CFLAGS) -o line2_ex $(line2_ex_objs)
	./line2_ex

# Create the Line 3 Object
line3_ex.o: line3_ex.c
	$(CC) $(CFLAGS) -c line3_ex.c

# Line 3 Objects
line3_ex_objs := line3_ex.o

# Line 3 Run Time Executable
line3_ex: $(line3_ex_objs)
	$(CC) $(CFLAGS) -o line3_ex $(line3_ex_objs)
	./line3_ex


# STUDENT - Create the Line 1 Object
line1.o: line1.c
	$(CC) $(CFLAGS) -c line1.c

# STUDENT - Line 1 Objects
line1_objs := line1.o

# STUDENT - Line 1 Run Time Executable
line1: $(line1_objs)
	$(CC) $(CFLAGS) -o line1 $(line1_objs)
	./line1


# STUDENT - Create the Line 2 Object
line2.o: line2.c
	$(CC) $(CFLAGS) -c line2.c

# STUDENT - Line 2 Objects
line2_objs := line2.o

# STUDENT - Line 2 Run Time Executable
line2: $(line2_objs)
	$(CC) $(CFLAGS) -o line2 $(line2_objs)
	./line2

# STUDENT - Create the Line 3 Object
line3.o: line3.c
	$(CC) $(CFLAGS) -c line3.c

# STUDENT - Line 3 Objects
line3_objs := line3.o

# STUDENT - Line 3 Run Time Executable
line3: $(line3_objs)
	$(CC) $(CFLAGS) -o line3 $(line3_objs)
	./line3


# Make Time Comparisons
time_comp: clean dyn_array_time_ineff stat_array_time stat_reg_time

# Make Haiku Example
haiku_ex: clean line1_ex line2_ex line3_ex

# Make Haiku Student
haiku: clean line1 line2 line3

# Executable Names
executable_names := void_recast stat_dyn_addr stat_dyn_func dyn_array_time stat_array_time stat_reg_time line1_ex line2_ex line3_ex line1 line2 line3

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
