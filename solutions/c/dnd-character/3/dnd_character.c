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
    
    dnd_character_t sheet;
    sheet.strength = ability();
    sheet.dexterity = ability();
    sheet.constitution = ability();
    sheet.intelligence = ability();
    sheet.wisdom = ability();
    sheet.charisma = ability();
    sheet.hitpoints = 10 + modifier(sheet.constitution);
    
    return sheet;
}
