#include <unordered_map>
#include <string>
#include <string_view>
#include <functional>

#include <gtest/gtest.h>

#include "ml_cpp_utils/string_hasher.hpp"

using namespace std::string_view_literals;

template <typename T>
using StringMap = std::unordered_map<std::string, T, ml::StringHasher, std::equal_to<>>;

TEST(string_hasher, simple) {
    auto map{StringMap<int>{}};
    map.emplace("foo", 1);

    char const* const foo_ptr{"foo"};
    static constexpr auto foo_sv{"foo"sv};

    auto find_ptr{map.find(foo_ptr)};
    auto find_sv{map.find(foo_sv)};

    ASSERT_NE(find_ptr, map.end());
    EXPECT_EQ(1, find_ptr->second);

    ASSERT_NE(find_sv, map.end());
    EXPECT_EQ(1, find_sv->second);
}
