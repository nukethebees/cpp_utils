find_package(GTest CONFIG REQUIRED)

add_executable(tests
    "test_file_io.cpp"
    "test_iter_utils.cpp"
)
target_link_libraries(tests PRIVATE 
    GTest::gtest_main 
    ml_cpp_utils::ml_cpp_utils
)

