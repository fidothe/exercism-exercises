#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t colors[]) {
    int value = 0;
    int column_base = 1; // units, tens, hundreds, etc
    for (int i = 1; i >= 0; i--) {
        // multiply by column base so you're adding at least 1 in the 
        // units column, 10 in the tens column, and so on...
        value += colors[i] * column_base; 
        column_base *= 10;
    }
    return value;
}
