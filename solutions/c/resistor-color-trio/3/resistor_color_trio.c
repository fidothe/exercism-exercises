#include "resistor_color_trio.h"
#include <math.h>

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
resistor_value_t color_code(resistor_band_t colors[]) {
    int value = 0;
    int column_base = 1; // units, tens, hundreds, etc
    int exponents = colors[2];
    for (int i = 1; i >= 0; i--) {
        if (i == 1 && colors[i] == 0) {
            exponents++;
        } else {
            value += colors[i] * column_base;
            column_base *= 10;
        }
    }
    resistor_value_t result = { 0, unit(exponents) };
    result.value = value * multiplier(result.unit, exponents);
    return result;
}

// Figure out what the unit should be based on how many
// zeroes are needed.
resistor_unit_t unit(int exponents) {
    if (exponents >= 9) {
        return GIGAOHMS;
    } else if (exponents >= 6) {
        return MEGAOHMS;
    } else if (exponents >= 3) {
        return KILOOHMS;
    } else {
        return OHMS;
    }
}

// Work out what the multiplier to the value should be
// based on the number of zeroes and the unit.
//
// For 8 zeroes and MEGAOHMS, the multiplier would be 10 ^ 2,
// or 10 ^ (8 - 6).
int multiplier(resistor_unit_t unit, int exponents) {
    int remaining_exponents = exponents;
    switch (unit) {
        case GIGAOHMS:
            remaining_exponents = exponents - 9;
            break;
        case MEGAOHMS:
            remaining_exponents = exponents - 6;
            break;
        case KILOOHMS:
            remaining_exponents = exponents - 3;
            break;
        case OHMS:
            break;
    }
    return pow(10, remaining_exponents);
}
