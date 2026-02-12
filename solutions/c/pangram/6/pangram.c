#include "pangram.h"

// A bit mask that's the result of setting least-significant bits 1-26:
// It's a constant, we don't need to calculate it every time...
const int PANGRAM_MASK = (1 << 26) -1;

bool is_pangram(const char *sentence) {
    if (!sentence) return false;

    // initialize the bit mask we're going to udpate to see if
    // have matched all the letters.
    int alphabet_mask = 0;

    // iterate through sentence, letter by letter
    for (; *sentence; sentence++) {
        // If the char is a letter, bitwise-or the alphabet mask
        // with itself minus the letter number (ASCII code
        // minus ASCII code for 'a' or 'A')
        if (is_lowercase(sentence)) {
            alphabet_mask |= match_mask(*sentence, 'a');
        } else if (is_uppercase(sentence)) {
            alphabet_mask |= match_mask(*sentence, 'A');
        }
        // return as soon we confirm we have a pangram
        if (alphabet_mask == PANGRAM_MASK) return true;
    }
    // If we hadn't returned already, we didn't find a pangram, so...
    return false;
}

bool is_lowercase(const char *letter) {
    return *letter >= 'a' && *letter <= 'z';
}

bool is_uppercase(const char *letter) {
    return *letter >= 'A' && *letter <= 'Z';
}

int match_mask(int letter, int a_offset) {
    return 1 << (letter - a_offset);
}
