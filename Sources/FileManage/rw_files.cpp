//
// Created by gamjun on 22/04/19.
//
#include <fstream>
#include <algorithm>
#include <iostream>
#include "rw_files.h"

using namespace std;

int *Rw_files::read_file(string file_path, int *n) {
    ifstream in_file(file_path);
    int *arr = (int *) malloc(
            count(std::istreambuf_iterator<char>(in_file), std::istreambuf_iterator<char>(), '\n') *
            sizeof(int));
    in_file.seekg(0);

    if (!arr) {
        cout << "Memory Allocation Failed";
        exit(1);
    } else {
        int i = 0;
        while (in_file >> arr[i]) {
            i++;
        }
        *n = i;
        in_file.close();
        return arr;
    }
}

void Rw_files::write_results(string archive_name, string result) {
    ofstream result_file;
    result_file.open("../Results/" + archive_name, ios::app);
    result_file << result;
    result_file.close();
}

void Rw_files::clear_file(string archive_name){
    ofstream file_to_clear;
    file_to_clear.open("../Results/" + archive_name, std::ofstream::out | std::ofstream::trunc);
    file_to_clear.close();
}