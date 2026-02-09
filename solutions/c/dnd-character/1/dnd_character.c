#include "dnd_character.h"

#include <time.h>
#include <math.h>
#include <stdlib.h>

int d6(void) {
    return (rand() % 6) + 1;
}

// Die comparator:
// Returns +ve if a is greater than b, -ve if a is less than b,
// and 0 if a is equal to b
int d_compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int ability(void) {
    int rolls[4] = { d6(), d6(), d6(), d6() };
    qsort(rolls, 4, sizeof(int), d_compare);
    int total = 0;
    for (int i = 1; i < 4; i++) {
        total += rolls[i];
    }    
    return total;
}

int modifier(int score) {
    // While, in theory, integer division will round down for me, 
    // in practice that rounds negative numbers UP...
    return floor((score - 10) / 2.0F); 
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
