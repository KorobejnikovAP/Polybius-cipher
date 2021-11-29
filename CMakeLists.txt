cmake_minimum_required(VERSION 2.8)

project(Polybius)
set(SOURCE_EXE main.cpp)
set(SOURCE_LIB Polybius.cpp)
add_library(Polybius STATIC ${SOURCE_LIB})
add_executable(main ${SOURCE_EXE})
target_link_libraries(main Polybius)