#include "pangram.h"
#include <string.h>

bool is_pangram(const char *sentence) {
    if (sentence == NULL || !*sentence) return false;

    char *alphabet[] = {
        "aA", "bB", "cC", "dD", "eE", "fF", "gG", "hH", "iI", "jJ",
        "kK", "lL", "mM", "nN", "oO", "pP", "qQ", "rR", "sS", "tT",
        "uU", "vV", "wW", "xX", "yY", "zZ"
    };
    int matched = 0;

    // Iterate through the alphabet,. one pair at a time
    for (int i = 0; i < 26; i++) {
        // if the sentence contains one of the letter pair, increment matched
        if (strpbrk(sentence, alphabet[i])) matched++;
    }

    // if we appended all letter pairs to the string, we have a pangram
    return matched == 26;
}
