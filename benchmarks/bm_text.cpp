
#include <limits>
#include <cstddef>
#include <cstdint>
#include <array>
#include <benchmark/benchmark.h>
#include "ml_cpp_utils/text.hpp"

template <typename T, std::size_t base>
void BM_num_to_string_min_max_zero(benchmark::State& state) {
    static constexpr T min = std::numeric_limits<T>::min();
    static constexpr T max = std::numeric_limits<T>::max();
    static constexpr T zero = T{0};
    static constexpr std::array<T, 3> values{zero, min, max};
    for (auto _ : state) {
        for (T v : values) {
            benchmark::DoNotOptimize(ml::num_to_string<base>(v));
        }
    }
    state.SetItemsProcessed(state.iterations() * values.size());
}

#define BENCH_ALL_TYPES(base)                                              \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::uint8_t, base)  \
        ->Name("BM_num_to_string_uint8_base" #base);                       \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::int8_t, base)   \
        ->Name("BM_num_to_string_int8_base" #base);                        \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::uint16_t, base) \
        ->Name("BM_num_to_string_uint16_base" #base);                      \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::int16_t, base)  \
        ->Name("BM_num_to_string_int16_base" #base);                       \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::uint32_t, base) \
        ->Name("BM_num_to_string_uint32_base" #base);                      \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::int32_t, base)  \
        ->Name("BM_num_to_string_int32_base" #base);                       \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::uint64_t, base) \
        ->Name("BM_num_to_string_uint64_base" #base);                      \
    BENCHMARK_TEMPLATE(BM_num_to_string_min_max_zero, std::int64_t, base)  \
        ->Name("BM_num_to_string_int64_base" #base);

BENCH_ALL_TYPES(2)
//BENCH_ALL_TYPES(8)
//BENCH_ALL_TYPES(10)
BENCH_ALL_TYPES(16)
