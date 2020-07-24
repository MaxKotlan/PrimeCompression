#pragma once
#include "../fieldsearch.h"

struct SearchState{
    SearchSettings& searchsettings;
    Field& fd;
    gmp::mpz_int& gx;
    gmp::mpz_int& s;
};


struct Action{    
    uint64_t id = 0x37458;
    void PrintInfo() const { std::cout << "A" << id << ": "; };
    void (*act)(SearchState &s, const Action& act);
    bool condition=false;
};