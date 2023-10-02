# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Create the Homework 3 Object
homework04.o: homework04.c
	$(CC) $(CFLAGS) -c homework04.c

# Create the search_and_sort Object
sort_and_search.o: sort_and_search.c
	$(CC) $(CFLAGS) -c sort_and_search.c

# homework04 Objects
homework04_objs := homework04.o sort_and_search.o

# Homework 3 Executable and Run
homework04: $(homework04_objs)
	$(CC) $(CFLAGS) -o homework04 $(homework04_objs) -lm
	./homework04

# Executable Names
executable_names := homework04

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
