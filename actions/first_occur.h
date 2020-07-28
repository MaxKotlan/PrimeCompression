#pragma once
#include "action.h"

class FirstOccur : public Action{
    public:
        FirstOccur() : foundat(26, 0), halt(false){};
        void operator()(SearchState &s);
        void load(boost::property_tree::ptree &_tree);
        Action* clone();
    private:
        std::vector<gmp::mpz_int> foundat; 
        gmp::mpz_int foundcount;
        bool halt;
};