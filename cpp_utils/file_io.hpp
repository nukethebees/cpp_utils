#pragma once

#include <filesystem>
#include <string>
#include <string_view>

namespace ml {
auto read_file(std::filesystem::path path) -> std::string;
void write_file(std::filesystem::path path, std::string_view contents);
}
