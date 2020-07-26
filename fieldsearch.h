#pragma once
#include "field.h"
#include "searchsettings.h"
#include "config.h"

class FieldSearch{
    public:
        FieldSearch(Config& conf) : _conf(conf), _f(conf.getFieldParameters()){
            std::cout << "Searching Field: " << conf.getFieldParameters().generator << "^x mod" << conf.getFieldParameters().moduli; 
        }
        void Search();
    protected:
        void NormalizeMarkedTargets(SearchSettings& s);
        void NormalizeTarget(Target &t, gmp::mpz_int &post_offset);
    private:
        Config& _conf;
        Field _f;
};