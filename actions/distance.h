#pragma once
#include "action.h"

class Distance : public Action{
    public:
        Distance() : locations(26){};
        void operator()(SearchState &s);
        void load(boost::property_tree::ptree &_tree);
        Action* clone();
    private:
        std::vector<std::vector<gmp::mpz_int>> locations;
        gmp::mpz_int checkoffset = 1;
        gmp::mpz_int printsize = 10;
};