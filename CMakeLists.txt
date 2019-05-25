cmake_minimum_required(VERSION 3.14)
project(Trabalho1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Trabalho1 Sources/main.cpp Sources/BubbleSort/bubble.cpp Sources/BubbleSort/bubble.h Sources/FileManage/rw_files.cpp Sources/FileManage/rw_files.h Sources/Worker/worker.cpp Sources/Worker/worker.h Sources/InsertionSort/insertion.cpp Sources/InsertionSort/insertion.h Sources/SelectionSort/selection.cpp Sources/SelectionSort/selection.h Sources/MergeSort/merge.cpp Sources/MergeSort/merge.h Sources/QuickSort/quick.cpp Sources/QuickSort/quick.h Sources/CountingSort/counting.cpp Sources/CountingSort/counting.h Sources/BucketSort/bucket.cpp Sources/BucketSort/bucket.h)