# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 19 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Create the Better Malloc Object
filePtrExBad.o: filePtrExBad.c
	$(CC) $(CFLAGS) -c filePtrExBad.c

# Better Malloc Objects
filePtrExBad_objs := filePtrExBad.o

# Better Malloc Executable
filePtrExBad: $(filePtrExBad_objs)
	$(CC) $(CFLAGS) -o filePtrExBad $(filePtrExBad_objs) -lm
	valgrind --leak-check=full ./filePtrExBad


# Create the Maze Object
filePtrExGood.o: filePtrExGood.c
	$(CC) $(CFLAGS) -c filePtrExGood.c

# Better Malloc Objects
filePtrExGood_objs := filePtrExGood.o

# Better Malloc Executable
filePtrExGood: $(filePtrExGood_objs)
	$(CC) $(CFLAGS) -o filePtrExGood $(filePtrExGood_objs) -lm
	valgrind --leak-check=full ./filePtrExGood


# Create the Better Malloc Object
file_locations.o: file_locations.c
	$(CC) $(CFLAGS) -c file_locations.c

# Better Malloc Objects
file_locations_objs := file_locations.o

# Better Malloc Executable
file_locations: $(file_locations_objs)
	$(CC) $(CFLAGS) -o file_locations $(file_locations_objs) -lm
	valgrind --leak-check=full ./file_locations


# Create the Better Malloc Object
FILE_example.o: FILE_example.c
	$(CC) $(CFLAGS) -c FILE_example.c

# Better Malloc Objects
FILE_example_objs := FILE_example.o

# Better Malloc Executable
FILE_example: $(FILE_example_objs)
	$(CC) $(CFLAGS) -o FILE_example $(FILE_example_objs) -lm
	valgrind --leak-check=full ./FILE_example test.txt



# Executable Names
executable_names := filePtrExBad filePtrExGood file_locations FILE_example

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
