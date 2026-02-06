#include "darts.h"
#include <stdio.h>

uint8_t score(coordinate_t landing_position) {
    float x = fabs(landing_position[0]);
    float y = fabs(landing_position[1]);
    float distance = pythagorean_distance(x, y);

    if (distance > 10) return 0;
    if (distance > 5) return 1;
    return distance > 1 ? 5 : 10;
}

float pythagorean_distance(float x, float y) {
    float b_sq = pow(y, 2);
    float c_sq = pow(x, 2);
    float a_sq = b_sq + c_sq;
    return sqrt(a_sq);
}