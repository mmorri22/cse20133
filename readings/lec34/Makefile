# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 34 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Rule 1 - Recursion vs. a loop. The last command is EXPECTED to crash.
recursive_delete: recursive_delete.c
	$(CC) $(CFLAGS) recursive_delete.c -o recursive_delete -lm
	./recursive_delete 1000 recursive
	./recursive_delete 1000000 iterative
	./recursive_delete 1000000 recursive

# Rule 1 - The same test with a 64 KB stack, closer to an embedded processor
small_stack: recursive_delete.c
	$(CC) $(CFLAGS) recursive_delete.c -o recursive_delete -lm
	ulimit -s 64; ./recursive_delete 1000 recursive
	ulimit -s 64; ./recursive_delete 5000 recursive

# Rule 2 - Bounded vs. unbounded search. The last command is EXPECTED to be
# stopped by timeout, which plays the role of a watchdog.
bounded_find: bounded_find.c
	$(CC) $(CFLAGS) bounded_find.c -o bounded_find -lm
	./bounded_find 30 unbounded
	./bounded_find 30 bounded
	./bounded_find 35 bounded
	timeout 2 ./bounded_find 35 unbounded

# Rule 3 - A static node pool instead of malloc
node_pool: node_pool.c
	$(CC) $(CFLAGS) node_pool.c -o node_pool -lm
	./node_pool

# Executable Names
executable_names := recursive_delete bounded_find node_pool

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
