# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 38 In-Class Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# The Q used by make mission. Try: make mission Q=0.001
Q := 0.1

kalman_filter.o: kalman_filter.c kalman_filter.h
	$(CC) $(CFLAGS) -c kalman_filter.c

test_kf.o: test_kf.c kalman_filter.h
	$(CC) $(CFLAGS) -c test_kf.c

sensor_run.o: sensor_run.c kalman_filter.h
	$(CC) $(CFLAGS) -c sensor_run.c

# Build and run all 16 tests
test: kalman_filter.o test_kf.o
	$(CC) $(CFLAGS) -o test_kf test_kf.o kalman_filter.o -lm
	./test_kf

sensor_run: kalman_filter.o sensor_run.o
	$(CC) $(CFLAGS) -o sensor_run sensor_run.o kalman_filter.o -lm

# Filter the mission and write estimate.csv
mission: sensor_run
	./sensor_run calibration.csv mission.csv $(Q)

# The same mission with a sensor that develops a bias. EXPECTED to end with Error 1.
bias: sensor_run
	./sensor_run calibration.csv mission.csv $(Q) bias

# GCC's static analyzer
analyze:
	$(CC) $(CFLAGS) -fanalyzer -c kalman_filter.c test_kf.c sensor_run.c

# Executable Names
executable_names := test_kf sensor_run

# Make clean
clean:
	rm -rf *.o *.swp estimate.csv $(executable_names)
