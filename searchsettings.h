#pragma once
#include "field.h"
#include <vector>

namespace gmp = boost::multiprecision;

struct Target{
    std::vector<gmp::mpz_int> data;
    bool normalize = false;
    bool halt = false;
};

struct SearchSettings{
    gmp::mpz_int a_offset = 0;
    gmp::mpz_int index = 0;
    gmp::mpz_int pollingrate = 1000000;
    bool printmatches = true;
    bool printnonmatches = false;
    std::vector<Target> targets;
    PrintSettings printsettings;
};
