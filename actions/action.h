#pragma once
#include <boost/property_tree/ptree.hpp>
#include "../fieldsearch.h"

struct SearchState{
    SearchSettings& searchsettings;
    Field& fd;
    gmp::mpz_int& gx;
    gmp::mpz_int& s;
};


class Action{
    public:
        virtual void operator()(SearchState &s)=0;
        virtual void load(boost::property_tree::ptree &_tree)=0;
    private:
        uint64_t id = 0;
};