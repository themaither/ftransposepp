include(CTest)

configure_file(initialize.sh initialize.sh COPYONLY)
execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/initialize.sh)

add_executable(query ftr/query.cpp)
target_include_directories(query PRIVATE ../src)
add_test(FtrQuery query)

add_executable(database ftr/database.cpp)
target_include_directories(database PRIVATE ../src)
add_test(FtrDatabase database)

add_executable(tests_are_in ftr/tests_are_in.cpp)
target_include_directories(tests_are_in PRIVATE ../src)
add_test(TestsAreIn tests_are_in)

configure_file(ftr/input.sh input.sh COPYONLY)
add_test(Input input.sh)