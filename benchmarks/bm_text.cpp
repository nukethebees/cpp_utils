#include <cstddef>
#include <cstdint>

#include <benchmark/benchmark.h>

#include "ml_cpp_utils/text.hpp"

static constexpr std::size_t n_base_iters{1000};

static void BM_num_to_string__base2_size_t(benchmark::State& state) {
    for (auto _ : state) {
        for (std::size_t i{0}; i < n_base_iters; ++i) {
            benchmark::DoNotOptimize(ml::num_to_string<2>(i));
        }
    }
    state.SetItemsProcessed(state.iterations() * n_base_iters);
}
static void BM_num_to_string__base10_int64_positive(benchmark::State& state) {
    using T = std::int64_t;

    for (auto _ : state) {
        for (int i{0}; i < static_cast<T>(n_base_iters); ++i) {
            benchmark::DoNotOptimize(ml::num_to_string<10>(i * 100000));
        }
    }
    state.SetItemsProcessed(state.iterations() * n_base_iters);
}
static void BM_num_to_string__base10_int64_negative(benchmark::State& state) {
    using T = std::int64_t;

    for (auto _ : state) {
        for (int i{0}; i < static_cast<T>(n_base_iters); ++i) {
            benchmark::DoNotOptimize(ml::num_to_string<10>(-i * 100000));
        }
    }
    state.SetItemsProcessed(state.iterations() * n_base_iters);
}

BENCHMARK(BM_num_to_string__base2_size_t);
BENCHMARK(BM_num_to_string__base10_int64_positive);
BENCHMARK(BM_num_to_string__base10_int64_negative);
