#include <array>
#include <span>

#include <gtest/gtest.h>

#include "ml_cpp_utils/split_span.hpp"
#include "ml_cpp_utils/iter_utils.hpp"

static constexpr std::array<int, 6> values_0{0, 1, 2, 3, 4, 5};
static constexpr auto span_0{std::span(values_0)};

TEST(split_span, int_array_0_split_2) {
    static constexpr std::size_t n{2};
    auto const split{ml::split_span(span_0, n)};

    ASSERT_EQ(split.size(), n);
    EXPECT_TRUE(ml::iterables_equal(split[0], span_0.subspan(0, 3)));
    EXPECT_TRUE(ml::iterables_equal(split[1], span_0.subspan(3, 3)));
}
