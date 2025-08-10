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

TEST(num_to_string, binary_values) {
    std::vector<std::string_view> outputs{
        "0",
        "1",
        "10",
        "111",
    };
    std::vector<std::size_t> inputs{0, 1, 2, 7};

    ASSERT_EQ(inputs.size(), outputs.size());

    for (std::size_t i{0}; i < inputs.size(); ++i) {
        auto const& input{inputs[i]};
        auto const& output{outputs[i]};
        ASSERT_EQ(output, ml::num_to_string<2>(input));
    }
}

TEST(num_to_string, binary_unsigned) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<2>(0u), "0");
    EXPECT_EQ(num_to_string<2>(1u), "1");
    EXPECT_EQ(num_to_string<2>(2u), "10");
    EXPECT_EQ(num_to_string<2>(15u), "1111");
    EXPECT_EQ(num_to_string<2>(255u), "11111111");
}

TEST(num_to_string, binary_signed) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<2>(0), "0");
    EXPECT_EQ(num_to_string<2>(1), "1");
    EXPECT_EQ(num_to_string<2>(-1), "-1");
    EXPECT_EQ(num_to_string<2>(-2), "-10");
    EXPECT_EQ(num_to_string<2>(7), "111");
    EXPECT_EQ(num_to_string<2>(-7), "-111");
}

TEST(num_to_string, octal_unsigned) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<8>(0u), "0");
    EXPECT_EQ(num_to_string<8>(8u), "10");
    EXPECT_EQ(num_to_string<8>(64u), "100");
    EXPECT_EQ(num_to_string<8>(255u), "377");
}

TEST(num_to_string, octal_signed) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<8>(-8), "-10");
    EXPECT_EQ(num_to_string<8>(-64), "-100");
    EXPECT_EQ(num_to_string<8>(-255), "-377");
}

TEST(num_to_string, decimal_unsigned) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<10>(0u), "0");
    EXPECT_EQ(num_to_string<10>(123u), "123");
    EXPECT_EQ(num_to_string<10>(4294967295u), "4294967295"); // max uint32_t
}

TEST(num_to_string, decimal_signed) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<10>(0), "0");
    EXPECT_EQ(num_to_string<10>(-123), "-123");
    EXPECT_EQ(num_to_string<10>(2147483647), "2147483647"); // max int32_t
    EXPECT_EQ(num_to_string<10>(-2147483647), "-2147483647");
}

TEST(num_to_string, hex_unsigned) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<16>(0u), "0");
    EXPECT_EQ(num_to_string<16>(10u), "A");
    EXPECT_EQ(num_to_string<16>(255u), "FF");
    EXPECT_EQ(num_to_string<16>(4095u), "FFF");
}

TEST(num_to_string, hex_signed) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<16>(-10), "-A");
    EXPECT_EQ(num_to_string<16>(-255), "-FF");
    EXPECT_EQ(num_to_string<16>(-4095), "-FFF");
}

TEST(num_to_string, base36_unsigned) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<36>(0u), "0");
    EXPECT_EQ(num_to_string<36>(35u), "Z");
    EXPECT_EQ(num_to_string<36>(36u), "10");
    EXPECT_EQ(num_to_string<36>(71u), "1Z");
    EXPECT_EQ(num_to_string<36>(1295u), "ZZ");
}

TEST(num_to_string, base36_signed) {
    using ml::num_to_string;
    EXPECT_EQ(num_to_string<36>(-35), "-Z");
    EXPECT_EQ(num_to_string<36>(-36), "-10");
    EXPECT_EQ(num_to_string<36>(-71), "-1Z");
    EXPECT_EQ(num_to_string<36>(-1295), "-ZZ");
}
