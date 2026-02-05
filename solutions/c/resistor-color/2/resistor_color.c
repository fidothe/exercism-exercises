#include "resistor_color.h"
#include <stddef.h>

int color_code(resistor_band_t color) {
    return color;
}

resistor_band_t *colors(void) {
    static resistor_band_t all_colors[10];
    if (all_colors[1] == BROWN) { // has already been initialized
        return all_colors;
    }
    for(resistor_band_t i = BLACK; i < 10; i++) { // needs to be initialized
        all_colors[i] = i;
    }
    return all_colors;
}
