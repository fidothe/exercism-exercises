#include "grains.h"

#define NUM_SQUARES 64

// 1ul is 1 as an unsigned long, which ought to be 64-bits wide on modern systems. 
// Seems to be ideal for bit-shifting. The tests use 1ull (unsigned long long), so 
// I'll use that in this iteration to be in line with them.

// The NUM_SQUARES define is for readability, but all the bitshifting behaviour in total() relies
// on it being no more than 64, because we need to not wrap around

uint64_t square(uint8_t index) {
    if (index < 1 || index > NUM_SQUARES) {
        return 0;
    }
    return 1ull << (index - 1);
}

// Binary digits are powers of 2, so an N bit number where all the bits are 1 is 2^N,
// which is a short-cut for doing the raising-to-the-power and summing of this problem.
// 
// * Bit-shift 1 left by 1 less than the number of squares N, which
//   leaves the Nth bit 1 and the rest 0.
// * Subtract 1 from that to flip all the bits (Nth bit 0, the rest 1).
// * Bit-shift left by 1, so Nth bit is 1, 1st bit is 0 and the rest are 1.
// * Add 1, so all N bits are 1.
uint64_t total(void) {
    return (((1ull << (NUM_SQUARES - 1)) - 1) << 1) + 1;
}
