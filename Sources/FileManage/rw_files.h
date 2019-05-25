//
// Created by gamjun on 22/04/19.
//

#ifndef TRABALHO1_RW_FILES_H
#define TRABALHO1_RW_FILES_H

using namespace std;

class Rw_files {
public:
    static int *read_file(string file_path, int *n);

    static void write_results(string archive_name, string result);

    static void clear_file(string archive_name);
};


#endif //TRABALHO1_RW_FILES_H
