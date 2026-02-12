#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL || !*sentence) return false;

    char *alphabet = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    int matched = 0;
    char letter_pair[3] = "";

    // Iterate through the alphabet string one pair at a time
    for (; *alphabet; alphabet += 2) {
        strncpy(letter_pair, alphabet, 2);

        // if the sentence contains one of the letter pair, increment matched
        if (strpbrk(sentence, letter_pair)) matched++;
    }

    // if we appended all letter pairs to the string, we have a pangram
    return matched == 26;
}
