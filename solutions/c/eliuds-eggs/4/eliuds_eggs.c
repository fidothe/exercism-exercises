#include "eliuds_eggs.h"

#include <stdio.h>

int egg_count(int eggs_bitfield) {
    int eggs = 0;
    // if the bitfield is not zero, there must be a bit set 1 (an egg)
    while (eggs_bitfield) {
        eggs++;
        // but why does this work?
        eggs_bitfield &= eggs_bitfield - 1;
    }

    return eggs;
}
