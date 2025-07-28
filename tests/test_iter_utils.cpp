#include <array>
#include <span>

#include <gtest/gtest.h>

#include "ml_cpp_utils/iter_utils.hpp"

static constexpr std::array<int, 6> values_0{0, 1, 2, 3, 4, 5};
static constexpr std::array<int, 6> values_1{5, 4, 3, 2, 1, 1};

TEST(iterables_equal, int_arrays) {
    EXPECT_TRUE(ml::iterables_equal(values_0, values_0));
    EXPECT_FALSE(ml::iterables_equal(values_0, values_1));
}
