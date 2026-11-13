# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 34 In-Class Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Build and run the nominal test: load 6 commands, cancel command 103
cmd_queue: cmd_queue.c
	$(CC) $(CFLAGS) cmd_queue.c -o cmd_queue
	./cmd_queue commands.txt 103

# 20 commands arrive, but the spacecraft only has room for MAX_COMMANDS
burst: cmd_queue
	./cmd_queue burst.txt 205

# Corrupt one pointer, then cancel a command that does not exist.
# timeout plays the role of the watchdog.
fault: cmd_queue
	timeout 2 ./cmd_queue commands.txt 999 fault

# GCC's static analyzer
analyze: cmd_queue.c
	$(CC) $(CFLAGS) -fanalyzer cmd_queue.c -o cmd_queue

# Rule 3 checker: fails if any heap function appears in the code
check_heap:
	! grep -nE "\b(malloc|calloc|realloc|free)\(" cmd_queue.c
	@echo "Rule 3: no heap calls found"

# Executable Names
executable_names := cmd_queue

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
