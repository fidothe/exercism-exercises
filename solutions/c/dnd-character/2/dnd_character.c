#include "dnd_character.h"

#include <time.h>
#include <math.h>
#include <stdlib.h>

int d6(void) {
    return (rand() % 6) + 1;
}

int ability(void) {
    int min = 7;
    int total = 0;
    for (int i = 0; i < 4; i++) {
        int roll = d6();
        total += roll;
        min = (min < roll) ? min : roll;
    }
    return total - min;
}

int modifier(int score) {
    // turn (s - 10) / 2 into (s/2) - 5, which makes the negative rounding problem go away
    return (score / 2) - 5;
}

dnd_character_t make_dnd_character(void) {
    srand(time(NULL));  // seed RNG with current time
    int constitution = ability();
    int constitution_mod = modifier(constitution);
    dnd_character_t sheet = {
        ability(), // strength
        ability(), // dexterity
        constitution,
        ability(), // intelligence
        ability(), // wisdom
        ability(), // charisma
        10 + constitution_mod // hitpoints
    };
    return sheet;
}
