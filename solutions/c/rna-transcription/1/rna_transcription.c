#include "rna_transcription.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna) {
    if (!dna) return "";

    size_t len = strlen(dna) + 1;
    char *rna = malloc(len); // allocate string-length-plus-null-terminator
    memset(rna, '\0', len); // set all the chars in the string to the null terminator

    for (; *dna; dna++) {
        strcat(rna, base_pair_complement(dna));
    }
    return rna;
}

static const char *cytosine = "C";
static const char *guanine = "G";
static const char *thyamine = "T";
static const char *adenine = "A";

char *base_pair_complement(const char *base) {
    if (*base == *cytosine) return "G";
    if (*base == *guanine) return "C";
    if (*base == *thyamine) return "A";
    if (*base == *adenine) return "U";
    return "";
}
