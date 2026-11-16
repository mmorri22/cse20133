# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 39 Reading.

# bash is needed to load Cobra
SHELL := /bin/bash

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# The course installation of Cobra
COBRA_ENV := /escnfs/courses/fa26-cse-20133.01/public/cobra/cobra_env.sh

# Reading 39-1 - One kernel, four engines
precision: precision.c
	$(CC) $(CFLAGS) precision.c -o precision -lm
	./precision

# Reading 39-2 - Every tool from this unit, in order. Each step must pass
# before the next one runs.
qualify: precision.c
	@echo "== 1. Build with every warning as an error (Lecture 32, Rule 10)"
	$(CC) $(CFLAGS) precision.c -o precision -lm
	@echo "== 2. Static analysis on every path (Lecture 32)"
	$(CC) $(CFLAGS) -fanalyzer precision.c -o precision -lm
	@echo "== 3. Run under AddressSanitizer and UBSan (Lecture 32)"
	$(CC) $(CFLAGS) -fsanitize=address,undefined precision.c -o precision_san -lm
	./precision_san > /dev/null
	@echo "== 4. Run under valgrind (Lecture 32)"
	valgrind -q --error-exitcode=1 ./precision > /dev/null
	@echo "== 5. Power of Ten check with Cobra (Lecture 35)"
	source $(COBRA_ENV) && p10check precision.c
	@echo "== QUALIFICATION EVIDENCE COLLECTED"

# Executable Names
executable_names := precision precision_san

# Make clean
clean:
	rm -rf *.o *.swp _P10_.txt $(executable_names)
