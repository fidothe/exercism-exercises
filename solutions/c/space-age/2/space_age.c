#include "space_age.h"

const float ORBITAL_PERIODS[8] = {0.2408467, 0.61519726, 1.0, 
    1.8808158, 11.862615, 29.447498, 84.016846, 164.79132};
const float EARTH_YEAR = 31557600;

float age(planet_t planet, int64_t seconds) {
    if (planet < 0 || planet > 7) return INVALID_VALUE;
    return seconds / EARTH_YEAR / ORBITAL_PERIODS[planet];
}