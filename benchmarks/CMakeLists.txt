find_package(benchmark REQUIRED)

add_executable (benchmarks)
target_sources(benchmarks PRIVATE
    "main.cpp"
 "bm_text.cpp")

target_link_libraries(benchmarks PRIVATE
    benchmark::benchmark 
    ml_cpp_utils::ml_cpp_utils
)
