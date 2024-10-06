# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 7 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c2x $(FLAGS)


# Create the Void Recast
void_recast.o: void_recast.c
	$(CC) $(CFLAGS) -c void_recast.c

# Void Recast Objects
void_recast_objs := void_recast.o

# Void Recast Executable and Run 
void_recast: $(void_recast_objs)
	$(CC) $(CFLAGS) -o void_recast $(void_recast_objs)
	./void_recast


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


# Executable Names
executable_names := fib fib_memo void_recast

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
