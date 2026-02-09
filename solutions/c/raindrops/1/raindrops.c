#include "raindrops.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

void convert(char result[], int drops) {
    bool matched = false; 
    if (drops % 3 == 0) {
        strcat(result, "Pling");
        matched = true;
    }
    if (drops % 5 == 0) {
        strcat(result, "Plang");
        matched = true;
    }
    if (drops % 7 == 0) {
        strcat(result, "Plong");
        matched = true;
    }
    if (!matched) sprintf(result, "%d", drops);
}
