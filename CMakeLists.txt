cmake_minimum_required(VERSION 3.12)
project(untitled10)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled10 main.cpp brute_model.h brute_model.cpp markov.h markov.cpp model.h map_model.h map_model.cpp word_model.h word_model.cpp)