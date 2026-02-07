#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name) {
    const char *final_name = (name) ? name : "you";

    char *you = "One for ";
    char *me =", one for me.";
    
    strcpy(buffer, you);
    strcat(buffer, final_name);
    strcat(buffer, me);
}
