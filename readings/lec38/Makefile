# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 38 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Reading 38-1 - Characterize the sensor noise
noise_stats: noise_stats.c
	$(CC) $(CFLAGS) noise_stats.c -o noise_stats -lm
	./noise_stats calibration.csv

# Reading 38-1 - Moving average vs. exponential smoothing
smoothing: smoothing.c
	$(CC) $(CFLAGS) smoothing.c -o smoothing -lm
	./smoothing mission.csv

# Reading 38-2 - A one-dimensional Kalman filter, and tuning Q
kalman: kalman.c
	$(CC) $(CFLAGS) kalman.c -o kalman -lm
	./kalman mission.csv

# Reading 38-2 - The innovation as a fault detector.
# The second run is EXPECTED to end with Error 1: a confirmed sensor fault.
innovation: innovation.c
	$(CC) $(CFLAGS) innovation.c -o innovation -lm
	./innovation mission.csv
	./innovation mission.csv bias

# Executable Names
executable_names := noise_stats smoothing kalman innovation

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
