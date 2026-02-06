#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    // check for null
    if (!lhs || !rhs) return INVALID_INPUT;
    
    int distance = 0;
    // pointer magik
    for (; *lhs && *rhs; lhs++, rhs++) {
        if (*lhs != *rhs) distance++;
    }

    // if one char at current position in lhs/rhs is NOT \0, 
    // then one side is longer than the other (if both are \0 
    // they are)
    return (*lhs || *rhs) ? INVALID_INPUT : distance;
}
