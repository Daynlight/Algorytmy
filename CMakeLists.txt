cmake_minimum_required(VERSION 3.0)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "../bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "../output/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../output/")

file(GLOB_RECURSE src "*.cpp" "*.h")

project(Algorytmy VERSION 1.0)

add_executable(Algorytmy ${src})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Circuit-App)
set_property(TARGET Circuit-App PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>")
