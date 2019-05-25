//
// Created by gamjun on 22/04/19.
//

#include "selection.h"

inline void swap_selection(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Selection::doSelection(int arr[], int n, long long int &swap_count, long long int &comparison_count) {
    int i, j, min_idx, l;
    swap_count = 0;
    comparison_count = 0;
    l = n - 1;

    for (i = 0; i < l; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            comparison_count++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap_count++;
        swap_selection(&arr[min_idx], &arr[i]);
    }
}