add_library (cpp_utils STATIC)

target_sources(cpp_utils PRIVATE
    "file_io.cpp"
)
target_sources(cpp_utils PUBLIC
  FILE_SET HEADERS
  BASE_DIRS ../
  FILES
    "file_io.hpp"
)
