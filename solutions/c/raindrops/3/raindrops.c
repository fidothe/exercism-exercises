#include "raindrops.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
   int factor;
   const char *drop_sound;
} drop_sound_t;

static const drop_sound_t DROP_SOUNDS[] = {
    { 3, "Pling" },
    { 5, "Plang" },
    { 7, "Plong" }
};

static const int SOUNDS_LEN = sizeof(DROP_SOUNDS) / sizeof(DROP_SOUNDS[0]);

void convert(char result[], int drops) {
    for (int i = 0; i < SOUNDS_LEN; i++) {
        if (drops % DROP_SOUNDS[i].factor == 0) {
            strcat(result, DROP_SOUNDS[i].drop_sound);
        }
    }
    if (strlen(result) == 0) sprintf(result, "%d", drops);
}
