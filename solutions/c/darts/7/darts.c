#include "darts.h"

const float OUTER_RING = 10.0F;
const float MIDDLE_RING = 5.0F;
const float INNER_RING = 1.0F;

enum Score {
    Miss = 0,
    Outer = 1,
    Middle = 5,
    Inner = 10
};

uint8_t score(coordinate_t landing_position) {
    float distance = hypot(landing_position.x, landing_position.y);

    if (distance > OUTER_RING) return Miss;
    if (distance > MIDDLE_RING) return Outer;
    if (distance > INNER_RING) return Middle;
    return Inner;
}
