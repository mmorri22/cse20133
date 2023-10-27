# This is the Makefile for the Lecture 25 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Build the hanoi_bad object
hanoi_bad.o: hanoi_bad.c
	$(CC) $(CFLAGS) -c hanoi_bad.c

# All Objects
hanoi_bad_objects := hanoi_bad.o

# Compilation
hanoi_bad: $(hanoi_bad_objects)
	$(CC) $(CFLAGS) -o hanoi_bad $(hanoi_bad_objects) -lm
	valgrind --leak-check=full ./hanoi_bad 21


# Build the max_min object
max_min.o: max_min.c
	$(CC) $(CFLAGS) -c max_min.c

# All Objects
max_min_objects := max_min.o

# Compilation
max_min: $(max_min_objects)
	$(CC) $(CFLAGS) -o max_min $(max_min_objects) -lm
	valgrind --leak-check=full ./max_min

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
executable_names := max_min hanoi hanoi_bad

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)