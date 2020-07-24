#pragma once
#include "../fieldsearch.h"

struct SearchState{
    Field& fd;
    gmp::mpz_int& gx;
    gmp::mpz_int& s;
};

struct Action{    
    uint64_t id = 0x37458;
    std::function<void(SearchState&)> action;
    bool condition=false;
};