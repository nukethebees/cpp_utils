add_library (cpp_utils STATIC)
add_library(ml_cpp_utils::cpp_utils ALIAS cpp_utils)

target_sources(cpp_utils 
    PRIVATE
        "file_io.cpp"
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ../
        FILES "file_io.hpp"
)

