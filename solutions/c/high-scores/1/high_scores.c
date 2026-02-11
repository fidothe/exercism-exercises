#include "high_scores.h"

#include <stdlib.h>
#include <stdio.h>

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int max = 0;
    for (size_t i = 0; i < scores_len; i++) {
        max = scores[i] > max ? scores[i] : max;
    }
    return max;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output) {
    int sorted_scores[scores_len];

    // copy the scores to another array
    for (size_t i = 0; i < scores_len; i++) sorted_scores[i] = scores[i];
    
    // insertion sort the copied array
    for (size_t i = 1; i < scores_len; i++) {
        for (int j = i; j > 0 && (sorted_scores[j] < sorted_scores[j - 1]); j--) {
            int to_swap = sorted_scores[j - 1];
            sorted_scores[j - 1] = sorted_scores[j];
            sorted_scores[j] = to_swap;
        }
    }

    size_t top_n = 0;
    for (int i = scores_len - 1; i >= 0 && top_n < 3; i--, top_n++) {
        output[top_n] = sorted_scores[i];
    }
    // the final iteration of the loop will increment top_n, so it'll end up holding
    // the size of the array..
    return top_n;
}
