#pragma once
#include <iostream>

uint64_t power(uint64_t x, uint64_t y);
uint64_t powermod(uint64_t x, uint64_t y, uint64_t p);

uint64_t power_mod(uint64_t x, uint64_t y, uint64_t p);

/*template <class T>
T inline mod(T x, T p) {
    return ((T)(-1)+1 + x) % p;
}*/

int64_t inline mod(int64_t x, int64_t p) {
    return (((x %= p) < p) ? x+p : x);//(p + (x%p)) % p;//((x < 0) ? (p-x)%p : x);
}

/*
template <class T=uint16_t,uint8_t>
T inline mod(T x, T p) {
    return ((T)(-1) + x) % p;
}*/


//uint64_t inline mod(int64_t k, int64_t n) {
//    return (((k %= n) < n) ? k+n : k);
//}
