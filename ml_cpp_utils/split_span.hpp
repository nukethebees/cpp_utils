#pragma once

#include <cstddef>
#include <span>
#include <type_traits>
#include <utility>
#include <vector>

namespace ml {
template <typename C>
concept SpanConvertible = requires(C c) {
    { c.size() } -> std::convertible_to<std::size_t>;
    { c.data() };
} && std::is_pointer_v<decltype(std::declval<C>().data())>;

template <typename Container>
    requires SpanConvertible<Container>
auto split_span(Container&& container, std::size_t n) {
    using T = std::remove_reference_t<decltype(*container.data())>;
    using OutSpan = std::span<T, std::dynamic_extent>;

    auto span{OutSpan(container)};
    auto const n_values{span.size()};

    std::vector<OutSpan> out;
    out.reserve(std::min(n, n_values));

    auto const split_size{(n_values / n)};
    auto const remainder = n_values % n;

    std::size_t offset{0};
    for (std::size_t i{0}; i < n; i++) {
        auto const count{split_size + (i < remainder ? 1 : 0)};
        out.emplace_back(span.subspan(offset, count));
        offset += count;
    }

    return out;
}
}
