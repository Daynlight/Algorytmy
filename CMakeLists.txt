cmake_minimum_required(VERSION 3.0)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "output/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "output/")

file(GLOB_RECURSE src "*.cpp" "*.h" "*.hpp")

project(Algorytmy VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(Algorytmy ${src})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Algorytmy)
set_property(TARGET Algorytmy PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(Algorytmy PRIVATE Threads::Threads)

set(THREADS_PREFER_PTHREAD_FLAG ON)