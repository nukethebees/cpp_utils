#include <algorithm>
#include <iterator>

namespace ml {
template <typename IterableA, typename IterableB>
bool iterables_equal(IterableA const& a, IterableB const& b) {
    if (std::size(a) != std::size(b)) {
        return false;
    }

    return std::equal(std::begin(a), std::end(a), std::begin(b));
}
}
