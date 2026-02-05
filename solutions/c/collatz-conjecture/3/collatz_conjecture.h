#ifndef COLLATZ_CONJECTURE_H
#define COLLATZ_CONJECTURE_H

#include <stdbool.h>

#define ERROR_VALUE -1

int steps(int start);
bool is_even(int num);
int step(int start);

#endif
