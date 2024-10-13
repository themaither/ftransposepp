include(CTest)

configure_file(initialize.sh initialize.sh COPYONLY)
execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/initialize.sh)

add_executable(query ftr/query.cpp)
target_include_directories(query PRIVATE ../src)

configure_file(ftr/input.sh input.sh COPYONLY)