#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t colors[]) {
    int value = 0;
    int column_base = 1; // units, tens, hundreds, etc
    // Walk backwards through the array of colors because we're effectively
    // encoding a written base 10 number, so the largest value column is
    // in the left most position, and the smallest in the right.
    // 
    // Were we handling variable length value codes, we could simply get
    // the length of the colors array and plug it in as the starting position
    // for the loop
    for (int i = 1; i >= 0; i--) {
        // multiply by column base so you're adding at least 1 in the 
        // units column, 10 in the tens column, and so on...
        value += colors[i] * column_base; 
        column_base *= 10;
    }
    return value;
}
