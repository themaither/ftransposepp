cmake_minimum_required(VERSION 3.5)
project(ftransposepp)

add_executable(ftrq src/ftrq.cpp)
target_compile_features(ftrq PUBLIC cxx_std_23)