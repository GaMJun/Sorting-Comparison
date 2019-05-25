//
// Created by gamjun on 22/04/19.
//

#include "merge.h"

void merge(int arr[], int l, int m, int r, long long int &comparison_count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    comparison_count++;
    while (i < n1 && j < n2) {
        comparison_count++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    comparison_count++;
    while (i < n1) {
        comparison_count++;
        arr[k] = L[i];
        i++;
        k++;
    }
    comparison_count++;
    while (j < n2) {
        comparison_count++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge::doMerge(int arr[], long long int &comparison_count, int l, int r) {

    comparison_count++;
    if (l < r) {
        int m = l + (r - l) / 2;

        doMerge(arr, comparison_count, l, m);
        doMerge(arr, comparison_count, m + 1, r);

        merge(arr, l, m, r, comparison_count);
    }
}
