# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 13 Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flages for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Create the Better Malloc Object
better_malloc.o: better_malloc.c
	$(CC) $(CFLAGS) -c better_malloc.c

# Better Malloc Objects
better_malloc_objs := better_malloc.o

# Better Malloc Executable
better_malloc: $(better_malloc_objs)
	$(CC) $(CFLAGS) -o better_malloc $(better_malloc_objs) -lm
	valgrind --leak-check=full ./better_malloc


# Create the Better Malloc Long Int Object
better_malloc_li.o: better_malloc_li.c
	$(CC) $(CFLAGS) -c better_malloc_li.c

# Better Malloc Long Objects
better_malloc_li_objs := better_malloc_li.o

# Better Malloc Executable
better_malloc_li: $(better_malloc_li_objs)
	$(CC) $(CFLAGS) -o better_malloc_li $(better_malloc_li_objs) -lm
	valgrind --leak-check=full ./better_malloc_li


# Create the Better Malloc Float Object
better_malloc_float.o: better_malloc_float.c
	$(CC) $(CFLAGS) -c better_malloc_float.c

# Better Malloc Float Objects
better_malloc_float_objs := better_malloc_float.o

# Better Malloc Executable
better_malloc_float: $(better_malloc_float_objs)
	$(CC) $(CFLAGS) -o better_malloc_float $(better_malloc_float_objs) -lm
	valgrind --leak-check=full ./better_malloc_float


# Create the Better Malloc Double Object
better_malloc_double.o: better_malloc_double.c
	$(CC) $(CFLAGS) -c better_malloc_double.c

# Better Malloc Double Objects
better_malloc_double_objs := better_malloc_double.o

# Better Malloc Executable
better_malloc_double: $(better_malloc_double_objs)
	$(CC) $(CFLAGS) -o better_malloc_double $(better_malloc_double_objs) -lm
	valgrind --leak-check=full ./better_malloc_double


# Create the argc argv Object
argc_argv.o: argc_argv.c
	$(CC) $(CFLAGS) -c argc_argv.c

# argc argv Objects
argc_argv_objs := argc_argv.o

# argc argv Executable
argc_argv: $(argc_argv_objs)
	$(CC) $(CFLAGS) -o argc_argv $(argc_argv_objs) -lm


# Create the argc argv mod Object
argc_argv_mod.o: argc_argv_mod.c
	$(CC) $(CFLAGS) -c argc_argv_mod.c

# argc argv mod Objects
argc_argv_mod_objs := argc_argv_mod.o

# argc argv mod Executable
argc_argv_mod: $(argc_argv_mod_objs)
	$(CC) $(CFLAGS) -o argc_argv_mod $(argc_argv_mod_objs) -lm


# Executable Names
executable_names := better_malloc better_malloc_li better_malloc_float better_malloc_double argc_argv argc_argv_mod

# Make all
all: $(executable_names)

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
