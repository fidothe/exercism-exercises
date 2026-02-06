#include "darts.h"
#include <stdio.h>

uint8_t score(coordinate_t landing_position) {
    float distance = pythagorean_distance(fabs(landing_position[0]), fabs(landing_position[1]));

    if (distance > 10) return 0;
    if (distance > 5) return 1;
    return distance > 1 ? 5 : 10;
}

float pythagorean_distance(float x, float y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}