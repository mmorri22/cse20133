# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 37 In-Class Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

fault_protection.o: fault_protection.c fault_protection.h
	$(CC) $(CFLAGS) -c fault_protection.c

test_fp.o: test_fp.c fault_protection.h
	$(CC) $(CFLAGS) -c test_fp.c

thermal_run.o: thermal_run.c fault_protection.h
	$(CC) $(CFLAGS) -c thermal_run.c

# Build and run all 20 tests
test: fault_protection.o test_fp.o
	$(CC) $(CFLAGS) -o test_fp test_fp.o fault_protection.o
	./test_fp

# Fly the thermal scenario. Ending in safe mode returns EXIT_FAILURE.
mission: fault_protection.o thermal_run.o
	$(CC) $(CFLAGS) -o thermal_run thermal_run.o fault_protection.o
	./thermal_run thermal.csv

# GCC's static analyzer
analyze:
	$(CC) $(CFLAGS) -fanalyzer -c fault_protection.c test_fp.c thermal_run.c

# Executable Names
executable_names := test_fp thermal_run

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
