# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 36 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Reading 36-1 - How long until each counter wraps?
counter_limits: counter_limits.c
	$(CC) $(CFLAGS) counter_limits.c -o counter_limits -lm
	./counter_limits

# Reading 36-1 - Timeouts across the wraparound
wraparound: wraparound.c
	$(CC) $(CFLAGS) wraparound.c -o wraparound -lm
	./wraparound

# Reading 36-1 - Three ways to keep one day of 0.1 s ticks
tick_drift: tick_drift.c
	$(CC) $(CFLAGS) tick_drift.c -o tick_drift -lm
	./tick_drift

# Reading 36-2 - A torn read of a two-part counter
torn_read: torn_read.c
	$(CC) $(CFLAGS) torn_read.c -o torn_read -lm
	./torn_read

# Executable Names
executable_names := counter_limits wraparound tick_drift torn_read

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
