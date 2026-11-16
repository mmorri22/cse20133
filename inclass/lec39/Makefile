# Author: Prof. Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for the Lecture 39 In-Class Example.

# bash is needed to load Cobra
SHELL := /bin/bash

# gcc is for the compiler for C
CC := gcc

# CFLAGS are the compiler flags for when we compile C code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -Werror
CFLAGS := -std=c2x $(FLAGS)

# The course installation of Cobra
COBRA_ENV := /escnfs/courses/fa26-cse-20133.01/public/cobra/cobra_env.sh

# The engine is chosen HERE, at build time. Try: make qualify ENGINE=q15
ENGINE := fp32
SOURCES := qualify_engine.c reference.c engine_$(ENGINE).c

# Build and qualify one engine
test: $(SOURCES) engine.h
	$(CC) $(CFLAGS) $(SOURCES) -o qualify_$(ENGINE) -lm
	./qualify_$(ENGINE)

# The full qualification pipeline from Reading 39-2, for one engine
qualify: $(SOURCES) engine.h
	@echo "== 1. Build with every warning as an error"
	$(CC) $(CFLAGS) $(SOURCES) -o qualify_$(ENGINE) -lm
	@echo "== 2. Static analysis"
	$(CC) $(CFLAGS) -fanalyzer $(SOURCES) -o qualify_$(ENGINE) -lm
	@echo "== 3. AddressSanitizer and UBSan"
	$(CC) $(CFLAGS) -fsanitize=address,undefined $(SOURCES) -o qualify_$(ENGINE)_san -lm
	./qualify_$(ENGINE)_san > /dev/null
	@echo "== 4. Accuracy against the reference"
	./qualify_$(ENGINE)
	@echo "== 5. Power of Ten check with Cobra"
	source $(COBRA_ENV) && p10check engine_$(ENGINE).c
	@echo "== $(ENGINE): QUALIFICATION EVIDENCE COLLECTED"

# Every engine, one after another. Stops at the first engine that fails.
qualify_all:
	$(MAKE) --no-print-directory qualify ENGINE=fp32
	$(MAKE) --no-print-directory qualify ENGINE=q15
	$(MAKE) --no-print-directory qualify ENGINE=int8

# Make clean
clean:
	rm -rf *.o *.swp _P10_.txt qualify_fp32* qualify_q15* qualify_int8*
