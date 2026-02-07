#include "eliuds_eggs.h"

#include <stdio.h>

int egg_count(int eggs_bitfield) {
    int eggs = 0;
    // if the bitfield is not zero, there must be a bit set 1 (an egg)
    while (eggs_bitfield) {
        // bitfield & 1 returns 1 if the rightmost bit is 1.
        if (eggs_bitfield & 1) eggs ++;
        // bitshift right one bit
        eggs_bitfield >>= 1;
    }

    return eggs;
}
