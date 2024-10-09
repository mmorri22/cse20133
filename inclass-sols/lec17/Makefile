# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 12 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)


# Create the Fibonacci Object
fib.o: fib.c
	$(CC) $(CFLAGS) -c fib.c

# Fibonacci Objects
fib_objs := fib.o

# Fibonacci Executable and Run
fib: $(fib_objs)
	$(CC) $(CFLAGS) -o fib $(fib_objs)
	./fib


# Create the Fib Memo
fib_memo.o: fib_memo.c
	$(CC) $(CFLAGS) -c fib_memo.c

# Trace Objects
fib_memo_objs := fib_memo.o

# Trace Executable and Run
fib_memo: $(fib_memo_objs)
	$(CC) $(CFLAGS) -o fib_memo $(fib_memo_objs)
	valgrind --leak-check=full ./fib_memo


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
dyn_array_time_eff_objs := dyn_array_time.o

# Dynamic Array Run Time Executable
dyn_array_time_eff: $(dyn_array_time_eff_objs)
	$(CC) $(CFLAGS) -o dyn_array_time $(dyn_array_time_eff_objs)
	./dyn_array_time_eff


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



# Make Time Comparisons
time_comp: clean dyn_array_time stat_array_time stat_reg_time dyn_array_time_eff


# Executable Names
executable_names := stat_dyn_func dyn_array_time stat_array_time stat_reg_time dyn_array_time_eff

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
