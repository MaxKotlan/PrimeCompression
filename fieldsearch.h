#pragma once
#include "field.h"
#include "searchsettings.h"
#include "config.h"

class FieldSearch{
    public:
        FieldSearch(Field &f) : _f(f) { }
        void Search(SearchSettings ssettings, Config& conf);
    protected:
        void NormalizeMarkedTargets(SearchSettings& s);
        void NormalizeTarget(Target &t, gmp::mpz_int &post_offset);
    private:
        Field _f;
};