#include "collatz_conjecture.h"

int steps(int start) {
    if (start < 1) {
        return ERROR_VALUE;
    }
    return step(start, 0);
}

bool is_even(int num) {
    return num % 2 == 0;
}

int step(int start, int step_num) {
    if (start == 1) { return step_num; }
    int next_step = step_num + 1;
    int next_value = is_even(start) ? start / 2 : (start * 3) + 1;
    return step(next_value, next_step);
}
