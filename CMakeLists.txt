cmake_minimum_required(VERSION 3.21)
project(wiper)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp FileWiper.cpp FileWiper.h Scanner.cpp Scanner.h FileProcessor.cpp FileProcessor.h FileQueue.cpp FileQueue.h)
