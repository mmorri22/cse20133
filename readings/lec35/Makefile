# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 35 Reading.

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# Rule 5 - assert() with and without NDEBUG. The last command is EXPECTED to abort.
asserts: assert_ndebug.c
	$(CC) $(CFLAGS) assert_ndebug.c -o assert_ndebug -lm
	$(CC) $(CFLAGS) -DNDEBUG assert_ndebug.c -o assert_ndebug_off -lm
	./assert_ndebug limit.txt
	./assert_ndebug_off limit.txt
	./assert_ndebug missing.txt

# Rule 5 - Holzmann's recovery assertion
recovery_assert: recovery_assert.c
	$(CC) $(CFLAGS) recovery_assert.c -o recovery_assert -lm
	./recovery_assert

# Rule 6 - This is EXPECTED to fail to compile
shadow: shadow.c
	$(CC) $(CFLAGS) shadow.c -o shadow -lm

# Rule 7 - This is EXPECTED to fail to compile
nodiscard: nodiscard.c
	$(CC) $(CFLAGS) nodiscard.c -o nodiscard -lm

# Rule 8 - Macros vs. functions
macros: macros.c
	$(CC) $(CFLAGS) macros.c -o macros -lm
	./macros


cmd_queue: cmd_queue.c
	$(CC) $(CFLAGS) cmd_queue.c -o cmd_queue -lm
	./cmd_queue

# Executable Names
executable_names := assert_ndebug assert_ndebug_off recovery_assert shadow nodiscard macros cmd_queue

# Make clean
clean:
	rm -rf *.o *.swp $(executable_names)
