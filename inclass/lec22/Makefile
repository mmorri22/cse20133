# This is the Makefile for the Lecture 22 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Build the main object
argc_argv.o: argc_argv.c
	$(CC) $(CFLAGS) -c argc_argv.c

# All Objects
argc_argv_objects := argc_argv.o

# Compilation
argc_argv: $(argc_argv_objects)
	$(CC) $(CFLAGS) -o argc_argv $(argc_argv_objects) -lm

# Build the main object
structs.o: structs.c
	$(CC) $(CFLAGS) -c structs.c

# All Objects
structs_objects := structs.o

# Compilation
structs: $(structs_objects)
	$(CC) $(CFLAGS) -o structs $(structs_objects) -lm


# All executables
executable_names := argc_argv structs

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)