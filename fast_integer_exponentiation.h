#pragma once
#include <iostream>

uint64_t power(uint64_t x, uint64_t y);
uint64_t powermod(uint64_t x, uint64_t y, uint64_t p);

uint64_t inline mod(int64_t k, int64_t n) {
    return (((k %= n) < n) ? k+n : k);
}
