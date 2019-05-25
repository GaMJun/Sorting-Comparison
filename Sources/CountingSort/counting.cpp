//
// Created by gamjun on 23/04/19.
//

#include <cstring>
#include <cstdlib>
#include "counting.h"

void Counting::doCounting(int arr[], int n, long long int &swap_count, long long int &comparison_count) {

    int *counter = nullptr, *output = nullptr, i = 0, k = -1;


    for (i = 0; i < n; i++) {
        comparison_count++;
        if (arr[i] > k) {
            k = arr[i];
        }
    }

    counter = (int *) malloc((sizeof(int) * k) + sizeof(int));

    for (i = 0; i <= k; i++) {
        counter[i] = 0;
    }

    for (i = 0; i < n; i++) {
        counter[arr[i]]++;
    }

    for (i = 1; i <= k; i++) {
        counter[i] = counter[i] + counter[i - 1];
    }

    output = (int *) malloc(sizeof(int) * n);

    for (i = n-1; i >= 0; i--) {
        output[counter[arr[i]]-1] = arr[i];
        counter[arr[i]]--;
    }

    free(counter);
    free(output);
}