# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Homework 9.
# It is provided for you. Read it carefully: Part 1 of report.txt asks about it,
# and you will write a Makefile like it for the Final Project.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# LIBS are the libraries linked at the end of the command (serial OpenBLAS)
LIBS := -l:libopenblas.so.0 -lm

# A small sweep, so valgrind finishes in reasonable time
SMALL := -DMAX_SIZE=200 -DREPEATS=1

hw09.o: hw09.c matmul.h epsilon.h
	$(CC) $(CFLAGS) -c hw09.c

matmul.o: matmul.c matmul.h
	$(CC) $(CFLAGS) -c matmul.c

epsilon.o: epsilon.c epsilon.h
	$(CC) $(CFLAGS) -c epsilon.c

hw09_objs := hw09.o matmul.o epsilon.o

hw09: $(hw09_objs)
	$(CC) $(CFLAGS) -o hw09 $(hw09_objs) $(LIBS)
	./hw09 results.csv

analyze:
	$(CC) $(CFLAGS) -fanalyzer -c hw09.c matmul.c epsilon.c

valgrind:
	$(CC) $(CFLAGS) $(SMALL) -o hw09_small hw09.c matmul.c epsilon.c $(LIBS)
	valgrind --leak-check=full ./hw09_small results_small.csv

clean:
	rm -rf *.o *.swp hw09 hw09_small results_small.csv
