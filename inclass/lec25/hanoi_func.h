#ifndef HANOI_FUNC_H
#define HANOI_FUNC_H

#include "stack.h"

void move(stack* source, stack* destination, int* numMoves);

void hanoi( int n, stack* source, stack* destination, stack* auxillary, int* numMoves);

#endif