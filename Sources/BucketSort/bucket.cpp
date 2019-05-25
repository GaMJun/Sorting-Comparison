//
// Created by gamjun on 23/04/19.
//

#include <cstdlib>
#include <vector>
#include "bucket.h"

using namespace std;

void Bucket::doBucket(int arr[], int n, long long int &swap_count, long long int &comparison_count) {
    int minValue = arr[0];
    int maxValue = arr[0];

    for (int i = 1; i < n; i++) {
        comparison_count += 2;
        if (arr[i] > maxValue)
            maxValue = arr[i];
        if (arr[i] < minValue)
            minValue = arr[i];
    }

    int bucketLength = maxValue - minValue + 1;
    vector<int> *bucket = new vector<int>[bucketLength];

    for (int i = 0; i < bucketLength; i++) {
        bucket[i] = vector<int>();
    }

    for (int i = 0; i < n; i++) {
        bucket[arr[i] - minValue].push_back(arr[i]);
    }

    int k = 0;
    for (int i = 0; i < bucketLength; i++) {
        int bucketSize = bucket[i].size();
        comparison_count++;
        if (bucketSize > 0) {
            for (int j = 0; j < bucketSize; j++) {
                arr[k] = bucket[i][j];
                k++;
            }
        }
    }
}
