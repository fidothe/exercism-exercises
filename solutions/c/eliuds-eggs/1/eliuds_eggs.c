#include "eliuds_eggs.h"

int egg_count(uint64_t eggs_bitfield) {
    // assuming a maximum of 64 hens...
    int eggs = 0;
    for (int i =0; i < 64; i++) {
        // if the number is odd, the right-most bit is 1, so there's an egg.
        if (eggs_bitfield % 2 != 0) eggs++;
        // bitshift right 1 bit...
        eggs_bitfield = eggs_bitfield >> 1;
    }
    return eggs;
}
