#include "collatz_conjecture.h"

int steps(int start) {
    if (start < 1) {
        return ERROR_VALUE;
    }
    return step(start);
}

// This time using bitwise operators to determine
// if the int is even or odd

bool is_even(int num) {
    return !(num & 1);
}

// Use a loop for a recursion-free version, 
// and bitshifting right to divide by 2.
int step(int start) {
    int step_num = 0;
    int n = start;
    while (n != 1) {
        is_even(n) ? n = n >> 1 : (n = (n * 3) + 1);
        step_num++;
    }
    return step_num;
}
