#include "two_fer.h"
#include <stdio.h>
#include <string.h>

#define DEFINITELY_UNSAFE_BUFFER_SIZE (100)

void two_fer(char *buffer, const char *name) {
    // I'm trying to use snprintf to avid writing over the end of the 
    // buffer (buffer overflow), but we don't know the allocated sizeof
    // of it, so it's not really safe. Feels a tiny bit better than
    // sprintf though.
    snprintf(buffer, DEFINITELY_UNSAFE_BUFFER_SIZE, "One for %s, one for me.", (name && strlen(name) > 0) ? name : "you");
}
