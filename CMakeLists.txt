cmake_minimum_required(VERSION 3.5)
project(ftransposepp)

add_executable(ftrq src/ftrq.cpp)
target_include_directories(ftrq PRIVATE src)
target_compile_features(ftrq PUBLIC cxx_std_23)

include(CTest)

add_subdirectory("test")
add_test(test/query "ls")