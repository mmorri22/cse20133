# This is the Makefile for the Lecture 19 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)


# Build the main object
lec24.o: lec24.c
	$(CC) $(CFLAGS) -c lec24.c

# Build the sllist object
sllist.o: sllist.c
	$(CC) $(CFLAGS) -c sllist.c

# All Objects
lec24_objects := lec24.o sllist.o

# Compilation
lec24: $(lec24_objects)
	$(CC) $(CFLAGS) -o lec24 $(lec24_objects) -lm


# Build the main object
lec24_sol.o: lec24_sol.c
	$(CC) $(CFLAGS) -c lec24_sol.c

# Build the sllist object
sllist_sol.o: sllist_sol.c
	$(CC) $(CFLAGS) -c sllist_sol.c

# All Objects
lec24_sol_objects := lec24_sol.o sllist_sol.o

# Compilation
lec24_sol: $(lec24_sol_objects)
	$(CC) $(CFLAGS) -o lec24_sol $(lec24_sol_objects) -lm
	valgrind --leak-check=full ./lec24_sol

# All executables
executable_names := lec24 lec24_sol struct_align

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
