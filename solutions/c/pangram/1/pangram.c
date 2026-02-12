#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL || !*sentence) return false;

    char *alphabet = "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    char matched[53]  = "";
    char letter_pair[3] = "";

    // Iterate through the alphabet string one pair at a time
    for (; *alphabet; alphabet += 2) {
        strncpy(letter_pair, alphabet, 2);

        // if the sentence contains one of the letter pair, append
        // the letter pair to the matched string
        char *match = strpbrk(sentence, letter_pair);
        if (match) {
            strcat(matched, letter_pair);
        }
    }

    // if we appended all letter pairs to the string, we have a pangram
    return strlen(matched) == 52;
}
