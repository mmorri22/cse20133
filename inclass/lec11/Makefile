# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 7 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)


# Create the Trace Object
trace.o: trace.c
	$(CC) $(CFLAGS) -c trace.c

# Float Compile Objects
trace_objs := trace.o

# Float Compile Executable
trace: $(trace_objs)
	$(CC) $(CFLAGS) -o trace $(trace_objs)
	./trace


# Create the Trace Pointer Object
trace_ptr.o: trace_ptr.c
	$(CC) $(CFLAGS) -c trace_ptr.c

# Trace Pointer Objects
trace_ptr_objs := trace_ptr.o

# Float Compile Executable
trace_ptr: $(trace_ptr_objs)
	$(CC) $(CFLAGS) -o trace_ptr $(trace_ptr_objs)
	./trace_ptr


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
	./fib_memo




# Executable Names
executable_names := trace trace_ptr fib fib_memo

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
