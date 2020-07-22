#pragma once
#include "field.h"

struct Target{
    std::vector<gmp::mpz_int> data;
    bool normalize = false;
    bool halt = false;
};

struct SearchSettings{
    gmp::mpz_int a_offset = 0;
    gmp::mpz_int index = 0;
    gmp::mpz_int pollingrate = 1000000;
    bool printnonmatches = false;
    std::vector<Target> targets;
};

class FieldSearch{
    public:
        FieldSearch(Field &f) : _f(f) { }
        void SetPrintSettings(PrintSettings psettings) { _printsettings = psettings; }
        void Search(SearchSettings ssettings);
    protected:
        void NormalizeMarkedTargets(SearchSettings& s);
        void NormalizeTarget(Target &t);
    private:
        PrintSettings _printsettings;
        Field _f;
};

void FieldSearch::NormalizeMarkedTargets(SearchSettings& s){
    for (auto &t : s.targets)
        if (t.normalize)
            NormalizeTarget(t);
}

void FieldSearch::NormalizeTarget(Target &t){
    for (auto &e : t.data)
        e = e - _printsettings.post_offset;
}


void FieldSearch::Search(SearchSettings ssettings){
    NormalizeMarkedTargets(ssettings);
    gmp::mpz_int initalelement = ssettings.targets[0].data[0];
    gmp::mpz_int s = (_f.getModuli()*(_f.getModuli()-1)+initalelement);
    gmp::mpz_int p = _f.getModuli();
    gmp::mpz_int _gx = gmp::powm(_f.getGenerator(), ssettings.index, _f.getModuli());
    for (gmp::mpz_int a("0"); a < _f.getModuli(); a++){
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);
        if (a%ssettings.pollingrate==0 && ssettings.printnonmatches){
            _f.printElementFieldEquation(ssettings.index);
            _f.print(_printsettings);
        }
        //static gmp::mpz_int prev = 0;
        for (Target &targ : ssettings.targets){
            if (_f.containsAt(ssettings.index, targ.data)){
                std::cout << "Found at: ";
                _f.printElementFieldEquation(ssettings.index);
                _f.print(_printsettings);
                std::cout << std::endl;
                if (targ.halt)
                    exit(0);
            }
        }
    }
    std::cout << "Search Complete" << std::endl;
}