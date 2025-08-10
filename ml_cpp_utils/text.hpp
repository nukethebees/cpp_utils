#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <string>
#include <type_traits>

namespace ml {
/**
 * @brief Checks if the character is an ASCII digit ('0'-'9').
 */
inline auto is_digit(char c) noexcept -> bool {
    return (c >= 48) && (c <= 57);
}
/**
 * @brief Checks if the character is an uppercase ASCII letter ('A'-'Z').
 */
inline auto is_upper_alpha(char c) noexcept -> bool {
    return (c >= 65) && (c <= 90);
}
/**
 * @brief Checks if the character is a lowercase ASCII letter ('a'-'z').
 */
inline auto is_lower_alpha(char c) noexcept -> bool {
    return (c >= 97) && (c <= 122);
}
/**
 * @brief Checks if the character is any ASCII letter (uppercase or lowercase).
 */
inline auto is_alpha(char c) noexcept -> bool {
    return is_upper_alpha(c) || is_lower_alpha(c);
}
/**
 * @brief Checks if the character is an ASCII letter or digit.
 */
inline auto is_alphanum(char c) noexcept -> bool {
    return is_digit(c) || is_alpha(c);
}
/**
 * @brief Checks if the character is valid as the first character of an identifier (ASCII letter or
 * underscore).
 */
inline auto is_identifier_char(char c) noexcept -> bool {
    return is_alpha(c) || (c == '_');
}
/**
 * @brief Checks if the character is valid as a non-initial character of an identifier (ASCII
 * letter, digit, or underscore).
 */
inline auto is_inner_identifier_char(char c) noexcept -> bool {
    return is_identifier_char(c) || is_digit(c);
}

template <std::size_t base, typename T>
    requires (std::is_integral_v<T> && (base >= 2))
auto num_to_string(T num) -> std::string {
    std::string out;

    bool is_negative{false};
    if constexpr (std::is_signed_v<T>) {
        if (num < 0) {
            num = -num;
            is_negative = true;
        }
    }

    static constexpr std::array<char, 36> digits{
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    while (num) {
        out += digits[num % base];
        num /= base;
    }

    if (out.empty()) {
        out += '0';
    }

    if (is_negative) {
        out += '-';
    }

    std::reverse(out.begin(), out.end());

    return out;
}
}
