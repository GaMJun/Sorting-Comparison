//
// Created by gamjun on 22/04/19.
//

#include "bubble.h"

inline void swap_bubble(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Bubble::doBubble(int arr[], int n, long long int &swap_count, long long int &comparison_count) {
    int i, j;
    swap_count = 0;
    comparison_count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            comparison_count++;
            if (arr[j] > arr[j + 1]) {
                swap_count++;
                swap_bubble(&arr[j], &arr[j + 1]);
            }
        }
    }
}