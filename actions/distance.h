#pragma once
#include "action.h"
#include <mutex>

class Distance : public Action{
    public:
        Distance() : locations(26){};
        void operator()(SearchState &s);
        void load(boost::property_tree::ptree &_tree);
        Action* clone();
    private:
        std::vector<std::vector<gmp::mpz_int>> locations;
        std::array<std::mutex, 26> locations_lock;
        gmp::mpz_int checkoffset = 1;
        gmp::mpz_int printsize = 10;
};