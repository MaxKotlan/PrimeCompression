#pragma once
#include "field.h"

class FieldSearch{
    public:
        FieldSearch(gmp::mpz_int generator, gmp::mpz_int moduli) : _f(generator, moduli) { }
        void setPrintSettings(PrintSettings psettings) { _printsettings = psettings; }
        void solutions(gmp::mpz_int index, gmp::mpz_int congruent);
        void printAllEquations(gmp::mpz_int index, gmp::mpz_int element);
        void printAllCoefficentCombinationsForSolution(gmp::mpz_int _index, gmp::mpz_int element);
        void printAllSolutionsUntil(gmp::mpz_int index, gmp::mpz_int element, gmp::mpz_int max);
        void search(std::vector<gmp::mpz_int> &elements);

    private:
        PrintSettings _printsettings;
        gmp::mpz_int pollingrate = 1000000;
        Field _f;
};

void FieldSearch::printAllEquations(gmp::mpz_int index, gmp::mpz_int element){
    gmp::mpz_int s = (_f.getModuli()*(_f.getModuli()-1)+element);
    //gmp::mpz_int s = element-1;
    //s %= _f.getModuli();
    //std::cout << s;
    std::vector<gmp::mpz_int> halt{ 'M'-'A','A'-'A', 'X' - 'A', 'W'-'A', 'E'-'A'};//, 'L'-'A', 'L'-'A'};//, 'L'-'A'};//, 'L'-'A' };
    gmp::mpz_int p = _f.getModuli();
    gmp::mpz_int _gx = gmp::powm(_f.getGenerator(), index, _f.getModuli());
    for (gmp::mpz_int a = 0; a < _f.getModuli(); a++){
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);
        if (a%pollingrate==0 && true){
            _f.printElementFieldEquation(index);
            _f.print(_printsettings);
        }
        //static gmp::mpz_int prev = 0;
        if (_f.containsAt(index, halt)){
            std::cout << "Found at: " << a << " ";
            _f.printElementFieldEquation(index);
            _f.print(_printsettings);
            std::cout << std::endl;
            //_f.printChar(10);
            //static gmp::mpz_int count = 0;
            //count++;
            //if (prev != 0 && a-prev != 13){
            //    std::cout << "DIVERGES! a:" << a << " : " << a-prev << std::endl;
                //exit(-1);
            //}
            //prev = a;
            //if (count == 10)
            //    exit(-1);
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