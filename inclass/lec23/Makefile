# This is the Makefile for the Lecture 23 Example.

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
struct_align_fix.o: struct_align_fix.c
	$(CC) $(CFLAGS) -c struct_align_fix.c

# All Objects
struct_align_fix_objects := struct_align_fix.o

# Compilation
struct_align_fix: $(struct_align_fix_objects)
	$(CC) $(CFLAGS) -o struct_align_fix $(struct_align_fix_objects) -lm


# Build the main object
mem_map.o: mem_map.c
	$(CC) $(CFLAGS) -c mem_map.c

# All Objects
mem_map_objects := mem_map.o

# Compilation
mem_map: $(mem_map_objects)
	$(CC) $(CFLAGS) -o mem_map $(mem_map_objects) -lm
	

# All executables
executable_names := struct_align struct_align_fix mem_map

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)