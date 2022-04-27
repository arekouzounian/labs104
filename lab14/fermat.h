#pragma once

#include <cstdint>
#include <vector>

std::uint32_t mod_exp(std::uint64_t base, std::uint64_t exponent, std::uint64_t mod);

bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests);
