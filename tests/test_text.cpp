#include <gtest/gtest.h>
#include <string_view>

#include "ml_cpp_utils/text.hpp"

// is_digit tests
TEST(is_char, is_digit) {
    static constexpr std::string_view valid{"0123456789"};
    static constexpr std::string_view invalid{
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=,./<>?;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_digit(c)) << "Failed for valid digit: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_digit(c)) << "Failed for invalid digit: " << c;
    }
}

// is_upper_alpha tests
TEST(is_char, is_upper_alpha) {
    static constexpr std::string_view valid{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    static constexpr std::string_view invalid{
        "abcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=,./<>?;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_upper_alpha(c)) << "Failed for valid upper alpha: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_upper_alpha(c)) << "Failed for invalid upper alpha: " << c;
    }
}

// is_lower_alpha tests
TEST(is_char, is_lower_alpha) {
    static constexpr std::string_view valid{"abcdefghijklmnopqrstuvwxyz"};
    static constexpr std::string_view invalid{
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=,./<>?;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_lower_alpha(c)) << "Failed for valid lower alpha: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_lower_alpha(c)) << "Failed for invalid lower alpha: " << c;
    }
}

// is_alpha tests
TEST(is_char, is_alpha) {
    static constexpr std::string_view valid{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    static constexpr std::string_view invalid{"0123456789!@#$%^&*()_+-=,./<>?;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_alpha(c)) << "Failed for valid alpha: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_alpha(c)) << "Failed for invalid alpha: " << c;
    }
}

// is_alphanum tests
TEST(is_char, is_alphanum) {
    static constexpr std::string_view valid{
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};
    static constexpr std::string_view invalid{"!@#$%^&*()_+-=,./<>?;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_alphanum(c)) << "Failed for valid alphanum: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_alphanum(c)) << "Failed for invalid alphanum: " << c;
    }
}

// is_identifier_char tests
TEST(is_char, is_identifier_char) {
    static constexpr std::string_view valid{
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"};
    static constexpr std::string_view invalid{"0123456789!@#$%^&*()-=+,.<>?/;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_identifier_char(c)) << "Failed for valid identifier char: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_identifier_char(c)) << "Failed for invalid identifier char: " << c;
    }
}

// is_inner_identifier_char tests
TEST(is_char, is_inner_identifier_char) {
    static constexpr std::string_view valid{
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789"};
    static constexpr std::string_view invalid{"!@#$%^&*()-=+,.<>?/;:'\"[]{}|`~ "};
    for (char c : valid) {
        EXPECT_TRUE(ml::is_inner_identifier_char(c))
            << "Failed for valid inner identifier char: " << c;
    }
    for (char c : invalid) {
        EXPECT_FALSE(ml::is_inner_identifier_char(c))
            << "Failed for invalid inner identifier char: " << c;
    }
}
