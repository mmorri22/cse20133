# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 36 In-Class Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

mission_clock.o: mission_clock.c mission_clock.h
	$(CC) $(CFLAGS) -c mission_clock.c

test_clock.o: test_clock.c mission_clock.h
	$(CC) $(CFLAGS) -c test_clock.c

# Build and run all 15 tests
test: mission_clock.o test_clock.o
	$(CC) $(CFLAGS) -o test_clock test_clock.o mission_clock.o
	./test_clock

# GCC's static analyzer
analyze:
	$(CC) $(CFLAGS) -fanalyzer -c mission_clock.c test_clock.c

# Executable Names
executable_names := test_clock

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
