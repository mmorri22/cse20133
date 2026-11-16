# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 35 In-Class Example.

# bash is needed to load Cobra
SHELL := /bin/bash

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# The course installation of Cobra
COBRA_ENV := /escnfs/courses/fa26-cse-20133.01/public/cobra/cobra_env.sh

# Build and run the nominal test
cmd_queue: cmd_queue.c flight_assert.h
	$(CC) $(CFLAGS) cmd_queue.c -o cmd_queue
	./cmd_queue commands.txt 103

# 20 commands arrive; only 16 fit
burst: cmd_queue
	./cmd_queue burst.txt 205

# Corrupt one pointer; the program should enter safe mode
fault: cmd_queue
	./cmd_queue commands.txt 999 fault

# GCC's static analyzer
analyze: cmd_queue.c flight_assert.h
	$(CC) $(CFLAGS) -fanalyzer cmd_queue.c -o cmd_queue

# Cobra's Power of Ten rule set
p10: cmd_queue.c
	source $(COBRA_ENV) && p10check cmd_queue.c

# Executable Names
executable_names := cmd_queue

# Make clean
clean:
	rm -rf *.o *.swp *.txt.bak _P10_.txt P10_*.txt $(executable_names)
