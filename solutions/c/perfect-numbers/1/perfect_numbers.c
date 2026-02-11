#include "perfect_numbers.h"

kind classify_number(int num) {
    if (num < 1) return ERROR;
    int aliquot_sum = 0;
    for (int factor = num - 1; factor > 0; factor--) {
        if (num % factor == 0) aliquot_sum += factor;
    }

    if (aliquot_sum == num) return PERFECT_NUMBER;
    return aliquot_sum < num ? DEFICIENT_NUMBER : ABUNDANT_NUMBER;
}