#include <filesystem>
#include <string_view>

#include <gtest/gtest.h>

#include "cpp_utils/file_io.hpp"

TEST(file_io, simple_read) {
    auto file_contents{ml::read_file("resources/file_read.txt")};
    ASSERT_EQ(file_contents, "foo\n");
}

TEST(file_io, simple_write) {
    std::filesystem::path const path{"out/simple_write.txt"};
    std::string_view const contents{"bar\n"};
    ml::write_file(path, contents);

    auto read{ml::read_file(path)};
    ASSERT_EQ(contents, read);
}
