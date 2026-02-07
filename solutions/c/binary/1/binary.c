#include "binary.h"

const int INVALID_INPUT = -1;
const char *one = "1";
const char *zero = "0";

int convert(const char *input) {
    if (!*input) return INVALID_INPUT;
    int result = 0;
    for (; *input; input++) {
        if (*input != *one && *input != *zero) return INVALID_INPUT;
        result = result << 1;
        if (*input == *one) result += 1;
    }
    return result;
}
