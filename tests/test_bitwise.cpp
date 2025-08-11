#include <cstdint>

#include <gtest/gtest.h>

#include "ml_cpp_utils/bitwise.hpp"

TEST(log2_size, numbers) {
    static_assert(ml::log2_size<std::uint8_t>() == 3);
    static_assert(ml::log2_size<std::uint16_t>() == 4);
    static_assert(ml::log2_size<std::uint32_t>() == 5);
    SUCCEED();
}

#define TEST_REVERSE(T, value, expected)                                                \
    static_assert(ml::reverse_bits(static_cast<T>(value)) == static_cast<T>(expected)); \
    ASSERT_EQ(static_cast<T>(expected), ml::reverse_bits(static_cast<T>(value)))

TEST(reverse_bits, uint8_t_basic) {
    TEST_REVERSE(std::uint8_t, 0b00000001, 0b10000000);
    TEST_REVERSE(std::uint8_t, 0b11110000, 0b00001111);
    TEST_REVERSE(std::uint8_t, 0b10101010, 0b01010101);
    TEST_REVERSE(std::uint8_t, 0b00000000, 0b00000000);
    TEST_REVERSE(std::uint8_t, 0b11111111, 0b11111111);
}

TEST(reverse_bits, int8_t_signed) {
    TEST_REVERSE(std::int8_t, 1, -128);
    TEST_REVERSE(std::int8_t, -1, -1); // 0xFF reversed is still 0xFF
}

TEST(reverse_bits, uint16_t) {
    TEST_REVERSE(std::uint16_t, 0x0001, 0x8000);
    TEST_REVERSE(std::uint16_t, 0x00FF, 0xFF00);
    TEST_REVERSE(std::uint16_t, 0xF0F0, 0x0F0F);
}

TEST(reverse_bits, int16_t_signed) {
    TEST_REVERSE(std::int16_t, 1, -32768);
    TEST_REVERSE(std::int16_t, -1, -1);
}

TEST(reverse_bits, uint32_t) {
    TEST_REVERSE(std::uint32_t, 0x00000001, 0x80000000);
    TEST_REVERSE(std::uint32_t, 0xF0F0F0F0, 0x0F0F0F0F);
}

TEST(reverse_bits, int32_t_signed) {
    TEST_REVERSE(std::int32_t, 1, -2147483648);
    TEST_REVERSE(std::int32_t, -1, -1);
}

TEST(reverse_bits, uint64_t) {
    TEST_REVERSE(std::uint64_t, 0x0000000000000001ULL, 0x8000000000000000ULL);
    TEST_REVERSE(std::uint64_t, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL);
}

TEST(reverse_bits, int64_t_signed) {
    TEST_REVERSE(std::int64_t, 1, INT64_MIN);
    TEST_REVERSE(std::int64_t, -1, -1);
}
