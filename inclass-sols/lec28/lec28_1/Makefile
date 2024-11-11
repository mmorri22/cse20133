# Author: Matthew Morrison
# E-mail: matt.morrison@nd.edu
#
# This is the Makefile for Lecture 26 In-Class - CSE 20133

# G++ is for the GCC compiler for C++
PP := g++

# CFLAGS are the compiler flages for when we compile C++ code in this course
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Werror
CXXFLAGS := -std=c++2a $(FLAGS)


# C++ File I/O Example
# Command: make file_io
file_io.o: file_io.cpp
	$(PP) $(CXXFLAGS) -c file_io.cpp

file_io_objs := file_io.o

file_io: $(file_io_objs)
	$(PP) $(CXXFLAGS) -o file_io $(file_io_objs) -lm

# C++ Call By Reference Example
# Command: make call_by
call_by.o: call_by.cpp
	$(PP) $(CXXFLAGS) -c call_by.cpp

call_by_objs := call_by.o

call_by: $(call_by_objs)
	$(PP) $(CXXFLAGS) -o call_by $(call_by_objs) -lm
	./call_by

# C++ vector example
# Command: make vector
vector.o: vector.cpp
	$(PP) $(CXXFLAGS) -c vector.cpp

vector_objs := vector.o

vector: $(vector_objs)
	$(PP) $(CXXFLAGS) -o vector $(vector_objs) -lm
	valgrind --leak-check=full ./vector


# C++ count_sort example
# Command: make count_sort
count_sort.o: count_sort.cpp
	$(PP) $(CXXFLAGS) -c count_sort.cpp

count_sort_objs := count_sort.o

count_sort: $(count_sort_objs)
	$(PP) $(CXXFLAGS) -o count_sort $(count_sort_objs) -lm
	./count_sort


# C++ sort_comp Example
# Command: make file_io
sort_comp.o: sort_comp.cpp
	$(PP) -std=c++2a -c sort_comp.cpp

sort_comp_objs := sort_comp.o

sort_comp: $(sort_comp_objs)
	$(PP) -std=c++2a -o sort_comp $(sort_comp_objs) -lm


# C++ std::stack Hanoi Example
# Command: make namespace
hanoi_stl.o: hanoi_stl.cpp
	$(PP) $(CXXFLAGS) -c hanoi_stl.cpp

hanoi_stl_objs := hanoi_stl.o

hanoi_stl: $(hanoi_stl_objs)
	$(PP) $(CXXFLAGS) -o hanoi_stl $(hanoi_stl_objs) -lm


# C++ Two Sums Example
# Command: make two_sums
two_sums.o: two_sums.cpp
	$(PP) $(CXXFLAGS) -c two_sums.cpp

two_sums_objs := two_sums.o

two_sums: $(two_sums_objs)
	$(PP) $(CXXFLAGS) -o two_sums $(two_sums_objs) -lm
	./two_sums


executable_names := file_io call_by vector count_sort sort_comp hanoi_stl two_sums

# Make clean
clean :
	rm -rf *.o $(executable_names)
