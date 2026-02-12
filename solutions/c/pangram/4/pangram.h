#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

bool is_pangram(const char *sentence);
bool is_lowercase(const char *letter);
bool is_uppercase(const char *letter);
int match_mask(int letter, int a_offset);

#endif
