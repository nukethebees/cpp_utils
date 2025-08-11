#pragma once

#include <array>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace ml {
template <typename T>
    requires (std::is_integral_v<T>)
constexpr auto log2_size() {
    auto width{sizeof(T) * 8};

    std::size_t size{0};
    while (width >>= 1) {
        size++;
    }

    return size;
}

template <typename T>
concept BitReversible = std::is_integral_v<T> && (sizeof(T) * 8 <= 64);

constexpr std::array<std::uint64_t, 6> reverse_bit_masks_64 = {
    0xAAAAAAAAAAAAAAAAULL, // 101010...
    0xCCCCCCCCCCCCCCCCULL, // 11001100...
    0xF0F0F0F0F0F0F0F0ULL, // 11110000...
    0xFF00FF00FF00FF00ULL, // 8-bit blocks
    0xFFFF0000FFFF0000ULL, // 16-bit blocks
    0xFFFFFFFF00000000ULL  // 32-bit blocks
};

template <BitReversible T, std::size_t N = log2_size<T>()>
constexpr auto create_masks_to_reverse_bits() {
    std::array<T, N> masks{};

    for (std::size_t i{0}; i < N; ++i) {
        masks[i] = static_cast<T>(reverse_bit_masks_64[i]);
    }

    return masks;
}

template <typename T>
    requires (std::is_integral_v<T> && std::is_unsigned_v<T>)
constexpr auto reverse_bits(T num) -> T {
    constexpr auto MASKS{create_masks_to_reverse_bits<T>()};

    std::size_t shift{1};
    for (auto mask : MASKS) {
        num = ((num & mask) >> shift) | ((num << shift) & mask);
        shift <<= 1;
    }

    return num;
}
template <typename T>
    requires (std::is_integral_v<T> && std::is_signed_v<T>)
constexpr auto reverse_bits(T num) -> T {
    using U = std::make_unsigned_t<T>;
    constexpr auto MASKS{create_masks_to_reverse_bits<U>()};
    auto unum{static_cast<U>(num)};

    std::size_t shift{1};
    for (auto mask : MASKS) {
        unum = ((unum & mask) >> shift) | ((unum << shift) & mask);
        shift <<= 1;
    }

    return static_cast<T>(unum);
}
}
