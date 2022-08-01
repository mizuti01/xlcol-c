cmake_minimum_required(VERSION 3.16.3)
project(xlcol)

set(DEST_DIR ${PROJECT_BINARY_DIR}/dist)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DEST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DEST_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DEST_DIR})

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_subdirectory(src/libxlcol)
add_subdirectory(src/command)
