# This is the Makefile for the Lecture 19 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)


# Build the main object
struct_align.o: struct_align.c
	$(CC) $(CFLAGS) -c struct_align.c

# All Objects
struct_align_objects := struct_align.o

# Compilation
struct_align: $(struct_align_objects)
	$(CC) $(CFLAGS) -o struct_align $(struct_align_objects) -lm


# Build the main object
lec23.o: lec23.c
	$(CC) $(CFLAGS) -c lec23.c

# Build the sllist object
sllist.o: sllist.c
	$(CC) $(CFLAGS) -c sllist.c

# All Objects
lec23_objects := lec23.o sllist.o

# Compilation
lec23: $(lec23_objects)
	$(CC) $(CFLAGS) -o lec23 $(lec23_objects) -lm


# Build the main object
lec23_sol.o: lec23_sol.c
	$(CC) $(CFLAGS) -c lec23_sol.c

# Build the sllist object
sllist_sol.o: sllist_sol.c
	$(CC) $(CFLAGS) -c sllist_sol.c

# All Objects
lec23_sol_objects := lec23_sol.o sllist_sol.o

# Compilation
lec23_sol: $(lec23_sol_objects)
	$(CC) $(CFLAGS) -o lec23_sol $(lec23_sol_objects) -lm
	valgrind --leak-check=full ./lec23_sol

# All executables
executable_names := lec23 lec23_sol struct_align

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
