#include <gtest/gtest.h>

#include "cpp_utils/file_io.hpp"

TEST(file_io, simeple_read) {
    auto file_contents{ml::read_file("resources/file_read.txt")};
    ASSERT_EQ(file_contents, "foo\n");
}
