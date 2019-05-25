//
// Created by gamjun on 22/04/19.
//
#include <cstdlib>    // malloc()
#include <unistd.h>   // sync()
#include <ctime>      // gettimeofday()
#include <iostream>
#include <cstring>
#include <string>

#include "worker.h"
#include "../BubbleSort/bubble.h"
#include "../FileManage/rw_files.h"
#include "../BubbleSort/bubble.h"
#include "../InsertionSort/insertion.h"
#include "../SelectionSort/selection.h"
#include "../MergeSort/merge.h"
#include "../QuickSort/quick.h"
#include "../CountingSort/counting.h"
#include "../BucketSort/bucket.h"

using namespace std;

// Coversão de nanosegundo para segundo
double timespecToSec(struct timespec *time) {
    return (double) (time->tv_sec * 1000000000 + time->tv_nsec) / 1000000000.0;
}

void doAllBubble(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Bubble::doBubble(arr, n, swap_count, comparison_count);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void doAllInsertion(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Insertion::doInsertion(arr, n, swap_count, comparison_count);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void doAllSelection(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Selection::doSelection(arr, n, swap_count, comparison_count);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void doAllMerge(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Merge::doMerge(arr, comparison_count, 0, n);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void doAllQuick(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Quick::doQuick(arr, swap_count, comparison_count, 0, n);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void doAllCounting(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Counting::doCounting(arr, n, swap_count, comparison_count);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void doAllBucket(int arr[], int n, string &result_time, string &result_comparison_count, string &result_swap_count) {

    long long int swap_count = 0, comparison_count = 0;

    struct timespec startCPU{}, endCPU{};

    sync(); // buffer pode conter algo de outro processo

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &startCPU); // relógio de CPU

    Bucket::doBucket(arr, n, swap_count, comparison_count);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &endCPU); // relógio de CPU

    result_time = result_time + to_string(timespecToSec(&endCPU) - timespecToSec(&startCPU)) + ", ";
    result_comparison_count = result_comparison_count + to_string(comparison_count) + ", ";
    result_swap_count = result_swap_count + to_string(swap_count) + ", ";
}

void Worker::do_work(string archive_name) {

    int *arr = nullptr, *arr_aux = nullptr, n = 0;
    string result_time[7];
    string result_comparison_count[7];
    string result_swap_count[7];

    for (int i = 1; i <= 15; i++) {
        cout << "Iteração: " << i << " Base " << archive_name << endl;
        arr = Rw_files::read_file("../DataSets/" + archive_name + "/" + to_string(i) + ".txt", &n);

        arr_aux = (int *) malloc(sizeof(int) * n);
        memcpy(arr_aux, arr, sizeof(int) * n);

        cout << "Bubble" << endl;
        doAllBubble(arr_aux, n, result_time[0], result_comparison_count[0], result_swap_count[0]);
        free(arr_aux);

        Rw_files::clear_file(archive_name + ".csv");
        Rw_files::write_results(archive_name + ".csv",
                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
        Rw_files::write_results(archive_name + ".csv",
                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
                                "\n Comparações, " + result_comparison_count[6] + "\n\n");

//        arr_aux = (int *) malloc(sizeof(int) * n);
//        memcpy(arr_aux, arr, sizeof(int) * n);
//
//        cout << "Insertion" << endl;
//        doAllInsertion(arr_aux, n, result_time[1], result_comparison_count[1], result_swap_count[1]);
//        free(arr_aux);
//
//        Rw_files::clear_file(archive_name + ".csv");
//        Rw_files::write_results(archive_name + ".csv",
//                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
//        Rw_files::write_results(archive_name + ".csv",
//                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
//                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
//                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
//                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
//                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
//                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
//                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
//                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
//                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
//                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
//                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
//                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
//                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
//                                "\n Comparações, " + result_comparison_count[6] + "\n\n");
//
//        arr_aux = (int *) malloc(sizeof(int) * n);
//        memcpy(arr_aux, arr, sizeof(int) * n);
//
//        cout << "Selection" << endl;
//        doAllSelection(arr_aux, n, result_time[2], result_comparison_count[2], result_swap_count[2]);
//        free(arr_aux);
//
//        Rw_files::clear_file(archive_name + ".csv");
//        Rw_files::write_results(archive_name + ".csv",
//                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
//        Rw_files::write_results(archive_name + ".csv",
//                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
//                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
//                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
//                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
//                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
//                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
//                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
//                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
//                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
//                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
//                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
//                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
//                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
//                                "\n Comparações, " + result_comparison_count[6] + "\n\n");
//
//        arr_aux = (int *) malloc(sizeof(int) * n);
//        memcpy(arr_aux, arr, sizeof(int) * n);
//
//        cout << "Merge" << endl;
//        doAllMerge(arr_aux, n, result_time[3], result_comparison_count[3], result_swap_count[3]);
//        free(arr_aux);
//
//        Rw_files::clear_file(archive_name + ".csv");
//        Rw_files::write_results(archive_name + ".csv",
//                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
//        Rw_files::write_results(archive_name + ".csv",
//                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
//                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
//                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
//                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
//                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
//                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
//                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
//                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
//                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
//                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
//                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
//                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
//                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
//                                "\n Comparações, " + result_comparison_count[6] + "\n\n");
//
//        arr_aux = (int *) malloc(sizeof(int) * n);
//        memcpy(arr_aux, arr, sizeof(int) * n);
//
//        cout << "Quick" << endl;
//        doAllQuick(arr_aux, n, result_time[4], result_comparison_count[4], result_swap_count[4]);
//        free(arr_aux);
//
//        Rw_files::clear_file(archive_name + ".csv");
//        Rw_files::write_results(archive_name + ".csv",
//                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
//        Rw_files::write_results(archive_name + ".csv",
//                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
//                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
//                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
//                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
//                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
//                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
//                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
//                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
//                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
//                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
//                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
//                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
//                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
//                                "\n Comparações, " + result_comparison_count[6] + "\n\n");
//
//        arr_aux = (int *) malloc(sizeof(int) * n);
//        memcpy(arr_aux, arr, sizeof(int) * n);
//
//        cout << "Count" << endl;
//        doAllCounting(arr_aux, n, result_time[5], result_comparison_count[5], result_swap_count[5]);
//        free(arr_aux);
//
//        Rw_files::clear_file(archive_name + ".csv");
//        Rw_files::write_results(archive_name + ".csv",
//                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
//        Rw_files::write_results(archive_name + ".csv",
//                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
//                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
//                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
//                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
//                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
//                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
//                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
//                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
//                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
//                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
//                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
//                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
//                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
//                                "\n Comparações, " + result_comparison_count[6] + "\n\n");
//
//        arr_aux = (int *) malloc(sizeof(int) * n);
//        memcpy(arr_aux, arr, sizeof(int) * n);
//
//        cout << "Bucket" << endl;
//        doAllBucket(arr_aux, n, result_time[6], result_comparison_count[6], result_swap_count[6]);
//        free(arr_aux);
//
        free(arr);
//
//        Rw_files::clear_file(archive_name + ".csv");
//        Rw_files::write_results(archive_name + ".csv",
//                                "Método, 100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000, 50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 1500000, 2000000\n");
//        Rw_files::write_results(archive_name + ".csv",
//                                "BubbleSort\n Tempo(sec), " + result_time[0] + "\n Swaps, " + result_swap_count[0] +
//                                "\n Comparações, " + result_comparison_count[0] + "\n\n" +
//                                "InsertionSort\n Tempo(sec), " + result_time[1] + "\n Swaps, " + result_swap_count[1] +
//                                "\n Comparações, " + result_comparison_count[1] + "\n\n" +
//                                "SelectionSort\n Tempo(sec), " + result_time[2] + "\n Swaps, " + result_swap_count[2] +
//                                "\n Comparações, " + result_comparison_count[2] + "\n\n" +
//                                "MergeSort\n Tempo(sec), " + result_time[3] + "\n Swaps, " + result_swap_count[3] +
//                                "\n Comparações, " + result_comparison_count[3] + "\n\n" +
//                                "QuickSort\n Tempo(sec), " + result_time[4] + "\n Swaps, " + result_swap_count[4] +
//                                "\n Comparações, " + result_comparison_count[4] + "\n\n" +
//                                "CountingSort\n Tempo(sec), " + result_time[5] + "\n Swaps, " + result_swap_count[5] +
//                                "\n Comparações, " + result_comparison_count[5] + "\n\n" +
//                                "BucketSort\n Tempo(sec), " + result_time[6] + "\n Swaps, " + result_swap_count[6] +
//                                "\n Comparações, " + result_comparison_count[6] + "\n\n");
    }

}