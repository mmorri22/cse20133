# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 32 In-Class Code Review.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# CFLAGS_O0 is identical but unoptimized, so valgrind reports exact lines
CFLAGS_O0 := -std=c2x -O0 -g -Wall -Wextra -Wconversion -Wshadow -Werror

# Step 1 - Build normally and run the nominal test
telemetry: telemetry.c
	$(CC) $(CFLAGS) telemetry.c -o telemetry -lm
	./telemetry nominal.txt

# Step 2 - GCC's static analyzer explores every path
analyze: telemetry.c
	$(CC) $(CFLAGS) -fanalyzer telemetry.c -o telemetry -lm

# Step 3 - AddressSanitizer watches every memory access at run time
asan: telemetry.c
	$(CC) $(CFLAGS) -fsanitize=address telemetry.c -o telemetry_asan -lm
	./telemetry_asan full.txt

# Step 4 - valgrind finds reads of memory that was never written
valgrind: telemetry.c
	$(CC) $(CFLAGS_O0) telemetry.c -o telemetry_O0 -lm
	valgrind --leak-check=full ./telemetry_O0 short.txt

# Time Permitting - a sanitizer check that is NOT part of -fsanitize=undefined
floatcheck: telemetry.c
	$(CC) $(CFLAGS) -fsanitize=undefined,float-cast-overflow telemetry.c -o telemetry_float -lm
	./telemetry_float hot.txt

# Executable Names
executable_names := telemetry telemetry_asan telemetry_O0 telemetry_float

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
