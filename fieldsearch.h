#pragma once
#include "field.h"
#include "searchsettings.h"
#include "config.h"

class FieldSearch{
    public:
        FieldSearch(Config& conf) : _conf(conf), _f(conf.getFieldParameters()){
            std::cout << "Searching Field: a*" << conf.getFieldParameters().generator << "^x+b mod" << conf.getFieldParameters().moduli << std::endl<< std::endl; 
        }
        void Search();
    protected:
        void NormalizeMarkedTargets(SearchSettings& s);
        void NormalizeTarget(Target &t, gmp::mpz_int &post_offset);
    private:
        Config& _conf;
        Field _f;
};