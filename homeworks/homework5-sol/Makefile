# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Create the homework05 Object
homework05.o: homework05.c
	$(CC) $(CFLAGS) -c homework05.c

# Create the rotations Objects
rotations.o: rotations.c
	$(CC) $(CFLAGS) -c rotations.c

# homework05 Objects
homework05_objs := homework05.o rotations.o

# homework05 Executable and Run
homework05: $(homework05_objs)
	$(CC) $(CFLAGS) -o homework05 $(homework05_objs) -lm
	valgrind --leak-check=full ./homework05

# Executable Names
executable_names := homework05

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
