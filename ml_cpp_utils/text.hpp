#pragma once

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
}
