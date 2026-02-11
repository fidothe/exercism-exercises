#include "perfect_numbers.h"

#include <math.h>
#include <stdio.h>

kind classify_number(int num) {
    if (num < 1) return ERROR;
    // 1 is a special case, so short-circuit
    if (num == 1) return DEFICIENT_NUMBER;

    // Reduce the space we have to iterate across. Pretty sure 
    // there's a 'better' way to do this, but I don't understand 
    // the examples I've seen of this...
    int max_factor = num / 2; 
    // We short-circuited 1, so the aliquot sum will always be >= 1
    int aliquot_sum = 1;
    for (int factor = max_factor; factor > 1; factor--) {
        if (num % factor == 0) aliquot_sum += factor;
    }
    
    if (aliquot_sum == num) return PERFECT_NUMBER;
    return aliquot_sum < num ? DEFICIENT_NUMBER : ABUNDANT_NUMBER;
}