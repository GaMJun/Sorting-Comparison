//
// Created by gamjun on 22/04/19.
//

#include "insertion.h"

void Insertion::doInsertion(int *arr, int n, long long int &swap_count, long long int &comparison_count) {
    int i, key, j;
    swap_count = 0;
    comparison_count = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        comparison_count += 2;
        while (j >= 0 && arr[j] > key) {
            comparison_count += 2;
            swap_count++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}