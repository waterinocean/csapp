find_package(Catch2 REQUIRED)

add_executable(test_converter test_converter.cpp)
target_link_libraries(test_converter PRIVATE Catch2::Catch2WithMain)

add_executable(test_linteger test_linteger.cpp ../src/linteger.cpp)
target_link_libraries(test_linteger PRIVATE Catch2::Catch2WithMain)
