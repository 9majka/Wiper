cmake_minimum_required(VERSION 3.21)
project(wiper)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

find_package(Threads REQUIRED)

add_executable(wiper main.cpp FileWiper.cpp FileWiper.h Scanner.cpp Scanner.h FileProcessor.cpp FileProcessor.h FileQueue.cpp FileQueue.h)
target_link_libraries(wiper PRIVATE Threads::Threads)
