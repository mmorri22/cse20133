# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 37 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Reading 37-1 - Triple modular redundancy and its limits
tmr_vote: tmr_vote.c
	$(CC) $(CFLAGS) tmr_vote.c -o tmr_vote -lm
	./tmr_vote

# Reading 37-1 - How scrubbing extends the life of a TMR value (takes a few seconds)
scrub: scrub.c
	$(CC) $(CFLAGS) scrub.c -o scrub -lm
	./scrub

# Reading 37-2 - Riding over transients with a leaky bucket
leaky_bucket: leaky_bucket.c
	$(CC) $(CFLAGS) leaky_bucket.c -o leaky_bucket -lm
	./leaky_bucket

# Reading 37-2 - A heater with and without hysteresis
thermostat: thermostat.c
	$(CC) $(CFLAGS) thermostat.c -o thermostat -lm
	./thermostat

# Executable Names
executable_names := tmr_vote scrub leaky_bucket thermostat

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
