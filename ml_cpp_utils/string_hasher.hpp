#pragma once

#include <cstddef>
#include <string>
#include <string_view>
#include <utility>

namespace ml {
/*
Useful typedefs:
---------------------------------------------------------------------------------------------------
using StringSet = std::unordered_set<std::string, string_hasher, std::equal_to<>>;

template <typename T>
using StringMap = std::unordered_map<std::string, T, string_hasher, std::equal_to<>>;
*/

// A helper struct to allow string_views and char pointers to be used in lookups
struct StringHasher {
    using is_transparent = void;

    auto operator()(char const* txt) const -> std::size_t {
        return std::hash<std::string_view>{}(txt);
    }
    auto operator()(std::string_view txt) const -> std::size_t {
        return std::hash<std::string_view>{}(txt);
    }
    auto operator()(std::string const& txt) const -> std::size_t {
        return std::hash<std::string>{}(txt);
    }
};
}
