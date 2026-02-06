#include "darts.h"
#include <stdio.h>

uint8_t score(coordinate_t landing_position) {
    float distance = pythagorean_distance(landing_position);

    if (distance > 10) return 0;
    if (distance > 5) return 1;
    if (distance > 1) return 5;
    return 10;
}

float pythagorean_distance(coordinate_t pos) {
    return sqrt(pow(fabs(pos[0]), 2) + pow(fabs(pos[1]), 2));
}