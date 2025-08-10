#include <cstddef>

#include <benchmark/benchmark.h>

#include "ml_cpp_utils/text.hpp"

static void BM_num_to_string(benchmark::State& state) {
    static constexpr std::size_t n{1000};

    for (auto _ : state) {
        for (std::size_t i{0}; i < n; ++i) {
            benchmark::DoNotOptimize(ml::num_to_string<2>(n));
        }
    }
    state.SetItemsProcessed(state.iterations() * n);
}

BENCHMARK(BM_num_to_string);
