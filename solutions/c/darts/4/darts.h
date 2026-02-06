#ifndef DARTS_H
#define DARTS_H

#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} coordinate_t;

uint8_t score(coordinate_t landing_position);
float pythagorean_distance(coordinate_t pos);

#endif
