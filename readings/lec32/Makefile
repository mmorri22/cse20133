# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 32 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# CFLAGS_O0 is identical, but with no optimization, for comparing -O0 and -O2
CFLAGS_O0 := -std=c2x -O0 -g -Wall -Wextra -Wconversion -Wshadow -Werror

# The new tools for this lecture
UBSAN := -fsanitize=undefined
ASAN := -fsanitize=address
ANALYZE := -fanalyzer


# Example 1 - Signed overflow, then the same code with UBSan
signed_overflow: signed_overflow.c
	$(CC) $(CFLAGS) signed_overflow.c -o signed_overflow -lm
	./signed_overflow

signed_overflow_ubsan: signed_overflow.c
	$(CC) $(CFLAGS) $(UBSAN) signed_overflow.c -o signed_overflow_ubsan -lm
	./signed_overflow_ubsan


# Example 2 - Integer promotion
promotion: promotion.c
	$(CC) $(CFLAGS) promotion.c -o promotion -lm
	./promotion


# Example 3 - Off by one. This one is SUPPOSED to fail to compile.
off_by_one: off_by_one.c
	$(CC) $(CFLAGS) off_by_one.c -o off_by_one -lm

# Example 3 - The same bug, hidden from the compiler, then caught by ASan
off_by_one_runtime: off_by_one_runtime.c
	$(CC) $(CFLAGS) off_by_one_runtime.c -o off_by_one_runtime -lm
	./off_by_one_runtime 7
	./off_by_one_runtime 8

off_by_one_asan: off_by_one_runtime.c
	$(CC) $(CFLAGS) $(ASAN) off_by_one_runtime.c -o off_by_one_asan -lm
	./off_by_one_asan 7
	./off_by_one_asan 8


# Example 4 - Uninitialized read at -O0 and -O2, then valgrind
uninit: uninit.c
	$(CC) $(CFLAGS_O0) uninit.c -o uninit_O0 -lm
	$(CC) $(CFLAGS) uninit.c -o uninit_O2 -lm
	./uninit_O0
	./uninit_O2
	valgrind ./uninit_O0


# Example 5 - Works on the test input, then -fanalyzer finds the leak
leaky_reading: leaky_reading.c
	$(CC) $(CFLAGS) leaky_reading.c -o leaky_reading -lm
	./leaky_reading temps.txt

leaky_analyze: leaky_reading.c
	$(CC) $(CFLAGS) $(ANALYZE) leaky_reading.c -o leaky_reading -lm


# Executable Names
executable_names := signed_overflow signed_overflow_ubsan promotion off_by_one off_by_one_runtime off_by_one_asan uninit_O0 uninit_O2 leaky_reading

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
