#pragma once
#include "field.h"

struct Target{
    std::vector<gmp::mpz_int> data;
    bool normalize = false;
    bool halt = false;
    //Target(std::initializer_list<Target> il) {
        //data
    //}
};

struct SearchSettings{
    gmp::mpz_int a_offset = 0;
    gmp::mpz_int index = 0;
    std::vector<Target> targets;
};

class FieldSearch{
    public:
        FieldSearch(gmp::mpz_int generator, gmp::mpz_int moduli) : _f(generator, moduli) { }
        void setPrintSettings(PrintSettings psettings) { _printsettings = psettings; }
        void solutions(gmp::mpz_int index, gmp::mpz_int congruent);
        void printAllEquations(SearchSettings ssettings);
        void printAllCoefficentCombinationsForSolution(gmp::mpz_int _index, gmp::mpz_int element);
        void printAllSolutionsUntil(gmp::mpz_int index, gmp::mpz_int element, gmp::mpz_int max);
        void search(std::vector<gmp::mpz_int> &elements);
    protected:
        void NormalizeMarkedTargets(SearchSettings& s);
        void NormalizeTarget(Target &t);
    private:
        PrintSettings _printsettings;
        gmp::mpz_int pollingrate = 1000000;
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


void FieldSearch::printAllEquations(SearchSettings ssettings){
    NormalizeMarkedTargets(ssettings);
    gmp::mpz_int initalelement = ssettings.targets[0].data[0];
    gmp::mpz_int s = (_f.getModuli()*(_f.getModuli()-1)+initalelement);
    //std::vector<gmp::mpz_int> halt{ 'C'-'A','L'-'A', 'A' - 'A', 'Y'-'A', 'J'-'A'};//, 'L'-'A', 'L'-'A'};//, 'L'-'A'};//, 'L'-'A' };
    gmp::mpz_int p = _f.getModuli();
    gmp::mpz_int _gx = gmp::powm(_f.getGenerator(), ssettings.index, _f.getModuli());
    for (gmp::mpz_int a("0"); a < _f.getModuli(); a++){
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);
        if (a%pollingrate==0 && true){
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

void FieldSearch::printAllCoefficentCombinationsForSolution(gmp::mpz_int index, gmp::mpz_int congruent){
    gmp::mpz_int _gx = 1;//powermod(_f.getGenerator(), index, _f.getModuli());
    for (gmp::mpz_int i = 0; i*_gx <= congruent; i++){
        _f.setA(i);
        _f.setB(congruent-i*_gx);
        _f.printElementFieldEquation(index);
        //_f.printChar(17);
        //_f.printElementFieldEquationGXPrecomputed(_gx);
        //_f.printFieldEquation();
    }
}

void FieldSearch::printAllSolutionsUntil(gmp::mpz_int index, gmp::mpz_int element, gmp::mpz_int max){
    for (gmp::mpz_int i = 0; i < max; i++)
        printAllCoefficentCombinationsForSolution(index, _f.getModuli()*i+element);
}

void FieldSearch::solutions(gmp::mpz_int index, gmp::mpz_int element) {
    for (gmp::mpz_int i = 0; i < 10; i++)
        std::cout << (_f.getModuli()*i+element)*(_f.getModuli()*i) << ((i!=9)?", ":"...");
    std::cout << std::endl;
};