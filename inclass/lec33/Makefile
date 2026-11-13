# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 33 In-Class Example.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# LIBS are the libraries linked at the end of the command (serial OpenBLAS)
LIBS := -l:libopenblas.so.0 -lm

# Build and run the matrix multiply comparison
matmul: matmul.c
	$(CC) $(CFLAGS) matmul.c -o matmul $(LIBS)
	./matmul

# Executable Names
executable_names := matmul

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
