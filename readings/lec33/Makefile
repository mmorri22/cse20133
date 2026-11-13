# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 33 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# BLAS is the serial OpenBLAS library installed on student13
BLAS := -l:libopenblas.so.0

# Reading 33-1 - Machine epsilon for float
float_epsilon: float_epsilon.c
	$(CC) $(CFLAGS) float_epsilon.c -o float_epsilon -lm
	./float_epsilon

# Reading 33-1 - The Patriot clock error, reconstructed
patriot: patriot.c
	$(CC) $(CFLAGS) patriot.c -o patriot -lm
	./patriot

# Reading 33-1 - Three ways to count one day of 0.1 s ticks
accumulate: accumulate.c
	$(CC) $(CFLAGS) accumulate.c -o accumulate -lm
	./accumulate

# Reading 33-2 - Row order vs. column order
row_vs_col: row_vs_col.c
	$(CC) $(CFLAGS) row_vs_col.c -o row_vs_col -lm
	./row_vs_col

# Reading 33-2 - Matrix multiply with BLAS. Libraries go AFTER the source file.
blas_dgemm: blas_dgemm.c
	$(CC) $(CFLAGS) blas_dgemm.c -o blas_dgemm $(BLAS) -lm
	./blas_dgemm

# Executable Names
executable_names := float_epsilon patriot accumulate row_vs_col blas_dgemm

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
