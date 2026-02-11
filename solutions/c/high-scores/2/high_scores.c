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
    // insertion sort the top 3 into output
    const int top_n = (int)scores_len > 3 ? 3 : scores_len;
    if (top_n == 1) { // when there's only 1, just return that.
        output[0] = scores[0];
        return 1; 
    }
    if (top_n == 2) { // when there's two, just max the two to figure out the order.
        int top = scores[0] > scores[1] ? 0 : 1;
        output[0] = scores[top];
        output[1] = scores[1 - top];
        return 2;
    }
    
    // there's 3 or more possibilities...
    for (int i = 0; i < top_n; i++) { output[i] = 0; }
    for (size_t i = 0; i < scores_len; i++) {
        int uninserted = 1; // track whether scores[i] has been inserted into the top N
        // loop through the top N scores, looking to see if this score is greater
        // than one of the existing top N.
        for (int j = 0; j < top_n && uninserted; j++) {
            if (scores[i] > output[j]) {
                // Shift the lower scores up 1 position
                // N.B. The int conversions are necessary because
                // (size_t)0 - 1 causes wraparound (where we go from 0 to the maximum postive
                // value of an unsigned size_t, not to -1) and we're in segfault land
                for (int k = top_n - 1; k >= j; k--) {
                    output[k + 1] = output[k];
                }                
                // insert the new top N score...
                output[j] = scores[i];
                uninserted = 0;
            }
        }
    }

    return top_n;
}
