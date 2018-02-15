project(base)
cmake_minimum_required (VERSION 2.6)

aux_source_directory(. DIR_MAIN)
# add_executable(Main "./sort/BubbleSort.cpp")
# add_executable(Main "./sort/InsertionSort.cpp")
# add_executable(Main "./sort/SelectionSort.cpp")
# add_executable(Main "./sort/MergeSort.cpp")
add_executable(Main "./sort/ShellSort.cpp")