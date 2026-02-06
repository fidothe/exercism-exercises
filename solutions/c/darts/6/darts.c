#include "darts.h"

uint8_t score(coordinate_t landing_position) {
    float distance = hypot(landing_position.x, landing_position.y);

    // ternary mess, more to remind myself how hard it is to read...
    return distance > 10.0F ? 0 : distance > 5.0F ? 1 : distance > 1.0F ? 5 : 10;
}
