//
// Created by gamjun on 22/04/19.
//

#include "quick.h"

void Quick::doQuick(int arr[], long long int &swap_count, long long int &comparison_count, int low, int high) {
    int pivot = arr[(low + high) / 2], i, j, aux;
    i = low;
    j = high;

    comparison_count++;
    while (i < j) {
        comparison_count++;
        comparison_count++;
        while (arr[i] < pivot) {
            comparison_count++;
            i++;
        }
        comparison_count++;
        while (arr[j] > pivot) {
            comparison_count++;
            j--;
        }
        comparison_count++;
        if (i <= j) {
            swap_count++;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }
    comparison_count++;
    if (j > low) {
        doQuick(arr, swap_count, comparison_count, low, j);
    }
    comparison_count++;
    if (i < high) {
        doQuick(arr, swap_count, comparison_count, j + 1, high);
    }

}