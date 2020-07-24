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
    void (*act)(SearchState &s);//=&Test;
    bool condition=false;
};