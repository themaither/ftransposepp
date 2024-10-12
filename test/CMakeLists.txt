include(CTest)

add_executable(query ftr/query.cpp)
target_include_directories(query PRIVATE ../src)

configure_file(ftr/input.sh input.sh COPYONLY)