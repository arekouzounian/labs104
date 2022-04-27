#include "fermat.h"

#include <vector>
#include <cassert>
#include <random>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <limits>
#include <stdexcept>

std::vector<bool> convert(std::uint64_t n, std::uint64_t b)
{
    std::vector<bool> ret; 
    for(int i = 0; n != 0; i++)
    {
        ret.push_back(n % b);
        n /= b; 
    }
    return ret;
}

// Calculates (base ^ exponent) % mod
std::uint32_t mod_exp(std::uint64_t base, std::uint64_t exponent, std::uint64_t mod) {
    //convert exponent to binary and put into a vector in reverse order 
    std::vector<bool> n = convert(exponent, 2);
    std::uint64_t x = 1; 
    std::uint64_t r = base % mod;
    for(size_t i = 0; i < n.size(); i++)
    {
        if (n[i]) 
            x = (x * r) % mod; 

        r = (r * r) % mod; 
    }

    return x; 
}

// Perform Fermat test on n.
// You should return true only if A^(n-1) % n == 1 for every A inside the tests vector
bool fermat_test(std::uint32_t n, const std::vector<std::uint32_t>& tests) {
    for(size_t i = 0; i < tests.size(); ++i)
    {
        if (mod_exp(tests[i], n-1, n) != 1)
            return false;
    }
    return true; 
}
