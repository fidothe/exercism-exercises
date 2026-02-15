#include "resistor_color_trio.h"
#include <math.h>

resistor_value_t color_code(resistor_band_t colors[]) {
    int value = 0;
    int column_base = 1; // units, tens, hundreds, etc
    // establish what the initial base should be -
    // orange-orange-red is 3300Ω, or 3.3kΩ, but our value is an int,
    // so it needs to be 3300Ω. orange-orange-orange is 33000, or 33kΩ,
    // which is an int. Orange-black-red would be 3000Ω, or 3kΩ, which
    // is an int. Black-orange-orange would also be 3kΩ.
    //
    // Walk backwards through the array of colors. We're effectively
    // encoding a written base 10 number, so the largest value column is
    // in the left most position, and the smallest in the right.
    //
    // If index 1 is black (0), add 1 to index 2's value from index 1.
    // Then add the remaining columns, multiplying by the base, which is
    // increased for each column.
    //
    // Figure out what the unit should be by removing the largest group
    // of 000's possible. That's the unit. Then multiply the first-columns
    // value by 1 x 10^N (where N is however many 0 columns are left).
    int exponents = colors[2];
    for (int i = 1; i >= 0; i--) {
        if (i == 1 && colors[i] == 0) {
            exponents++;
        } else {
            value += colors[i] * column_base;
            column_base *= 10;
        }
    }
    resistor_value_t result;
    int remaining_exponents = exponents;
    switch (exponents) {
        case 10:
        case 9:
            result.unit = GIGAOHMS;
            remaining_exponents = exponents - 9;
            break;
        case 8:
        case 7:
        case 6:
            result.unit = MEGAOHMS;
            remaining_exponents = exponents - 6;
            break;
        case 5:
        case 4:
        case 3:
            result.unit = KILOOHMS;
            remaining_exponents = exponents - 3;
            break;
        default:
            result.unit = OHMS;
    }
    result.value = value * pow(10, remaining_exponents);
    return result;
}
