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
	valgrind --leak-check=full ./lec24

##############################################
# Refer to this for your Homework 06 Makefile
##############################################

# Build the hanoi object
hanoi.o: hanoi.c
	$(CC) $(CFLAGS) -c hanoi.c

# Build the hanoi library object
hanoi_func.o: hanoi_func.c
	$(CC) $(CFLAGS) -c hanoi_func.c

# Build the stack object
stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

# All Objects
hanoi_objects := hanoi.o hanoi_func.o stack.o

# Compilation
hanoi: $(hanoi_objects)
	$(CC) $(CFLAGS) -o hanoi $(hanoi_objects) -lm

# All executables
executable_names := lec24 hanoi

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
