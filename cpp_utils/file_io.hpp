#pragma once

#include <filesystem>
#include <string>

namespace ml {
auto read_file(std::filesystem::path path) -> std::string;
}
