#include "collatz_conjecture.h"

int steps(int start) {
    if (start < 1) {
        return ERROR_VALUE;
    }
    return step(start);
}

bool is_even(int num) {
    return num % 2 == 0;
}

// Use a loop for a recursion-free version
int step(int start) {
    int step_num = 0;
    int n = start;
    while (n != 1) {
        is_even(n) ? n /= 2 : (n = (n * 3) + 1);
        step_num++;
    }
    return step_num;
}
