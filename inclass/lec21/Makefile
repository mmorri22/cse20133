# This is the Makefile for the Lecture 22 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Build the main object
structs.o: structs.c
	$(CC) $(CFLAGS) -c structs.c

# All Objects
structs_objects := structs.o

# Compilation
structs: $(structs_objects)
	$(CC) $(CFLAGS) -o structs $(structs_objects) -lm


# Build the main object
struct_align.o: struct_align.c
	$(CC) $(CFLAGS) -c struct_align.c

# All Objects
struct_align_objects := struct_align.o

# Compilation
struct_align: $(struct_align_objects)
	$(CC) $(CFLAGS) -o struct_align $(struct_align_objects) -lm


# Build the main object
struct_align_fix.o: struct_align_fix.c
	$(CC) $(CFLAGS) -c struct_align_fix.c

# All Objects
struct_align_fix_objects := struct_align_fix.o

# Compilation
struct_align_fix: $(struct_align_fix_objects)
	$(CC) $(CFLAGS) -o struct_align_fix $(struct_align_fix_objects) -lm

# All executables
executable_names := struct_align struct_align_fix

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)