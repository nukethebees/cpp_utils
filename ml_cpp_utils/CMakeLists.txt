add_library (ml_cpp_utils STATIC)
add_library(ml_cpp_utils::ml_cpp_utils ALIAS ml_cpp_utils)

target_sources(ml_cpp_utils 
    PRIVATE
        "file_io.cpp"
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ../
        FILES 
            "file_io.hpp"
            "iter_utils.hpp"
            "split_span.hpp"
            "string_hasher.hpp"
            "text.hpp"
)

