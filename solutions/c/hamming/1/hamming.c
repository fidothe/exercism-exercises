#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    int lhs_len = strlen(lhs);
    int rhs_len = strlen(rhs);
    
    if (lhs_len != rhs_len) return INVALID_INPUT;
    
    int distance = 0;
    for (int i = 0; i < lhs_len; i++) {
        distance += (lhs[i] == rhs[i] ? 0 : 1);
    }
    return distance;
}
