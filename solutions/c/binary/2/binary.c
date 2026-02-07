#include "binary.h"

const char *DIGIT_ONE = "1";
const char *DIGIT_ZERO = "0";

int convert(const char *input) {
    if (!*input) return INVALID;
    int result = 0;
    // Iterate over the input, bit shifting the result left by 1 each time.
    // If the input is a 1, add one to the result, so we build up the
    // input string bit pattern as a real bit pattern in result.
    for (; *input; input++) {
        if (*input != *DIGIT_ONE && *input != *DIGIT_ZERO) return INVALID;
        result = result << 1;
        if (*input == *DIGIT_ONE) result += 1;
    }
    return result;
}
