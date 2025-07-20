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
}
