#include <fstream>
#include <sstream>

#include "file_io.hpp"

namespace ml {
auto read_file(std::filesystem::path path) -> std::string {
    std::ifstream const t(path);
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

// Write a string to a file
void write_file(std::filesystem::path path, std::string_view contents) {
    std::ofstream out_stream{path};
    out_stream << contents;
}
}
