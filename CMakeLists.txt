cmake_minimum_required(VERSION 3.5)
project(ftransposepp)

add_executable(ftrq src/ftrq.cpp)
target_include_directories(ftrq PRIVATE src)
target_compile_features(ftrq PUBLIC cxx_std_23)

enable_testing()

add_subdirectory("test")
add_test(FtrqInput test/input.sh)
add_test(FtrQuery test/query)