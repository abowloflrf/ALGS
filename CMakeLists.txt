cmake_minimum_required(VERSION 3.0)
project(ALGS LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(./utils)
aux_source_directory(./leetcode LEETCODE_SRC)

# LeetCode
foreach(leetcodesrcfile ${LEETCODE_SRC})
    get_filename_component(lcproblem ${leetcodesrcfile} NAME_WE)
    add_executable(leetcode-${lcproblem} ${leetcodesrcfile})
endforeach(leetcodesrcfile ${LEETCODE_SRC})

