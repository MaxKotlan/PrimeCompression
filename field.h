#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <boost/multiprecision/gmp.hpp>
#include "fast_integer_exponentiation.h"

namespace gmp = boost::multiprecision;

struct PrintSettings{
    gmp::mpz_int range=0;
    gmp::mpz_int offset=0;
    gmp::mpz_int post_offset=0;
    gmp::mpz_int subfield=256;
    enum PrintMode{
        Dec,
        Hex,
        Char
    } printmode=PrintMode::Dec;
};

class Field{
    public:
        Field(gmp::mpz_int generator, gmp::mpz_int moduli);
        Field(gmp::mpz_int generator, gmp::mpz_int moduli, gmp::mpz_int a, gmp::mpz_int b);

        void inline setCoefficents(gmp::mpz_int a, gmp::mpz_int b) { _a = a; _b = b; }
        gmp::mpz_int inline getModuli() { return _p; };
        gmp::mpz_int inline getGenerator() { return _g; };
        gmp::mpz_int inline getA() { return _a; };
        gmp::mpz_int inline getB() { return _b; };
        void inline setA(gmp::mpz_int a) {_a = a;};
        void inline setB(gmp::mpz_int b) {_b = b;};
        gmp::mpz_int inline size() { return _p - 1; };
        void print(PrintSettings &psettings);
        bool containsAt(gmp::mpz_int index, std::vector<gmp::mpz_int> &elements);
        gmp::mpz_int getElement(gmp::mpz_int index) {
            gmp::mpz_int k = gmp::powm(_g, index,_p); 
            return ((_a * k+_b)%_p); 
        };
        void printElementFieldEquation(gmp::mpz_int index);
        void printElementFieldEquationGXPrecomputed(gmp::mpz_int gx);
        void printGeneralFieldEquation();

    protected:
        void printDec(PrintSettings &psettings);
        void printHex(PrintSettings &psettings);
        void printChar(PrintSettings &psettings);

    private:
        /*Coefficents used to modify standard exponential fields*/
        gmp::mpz_int _a;
        gmp::mpz_int _b;

        /*Generator and moduli*/
        gmp::mpz_int _g;
        gmp::mpz_int _p;
};

Field::Field(gmp::mpz_int generator, gmp::mpz_int moduli) : _g(generator), _p(moduli), _a(1), _b(0) {};

Field::Field(gmp::mpz_int generator, gmp::mpz_int moduli, gmp::mpz_int a, gmp::mpz_int b) : _g(generator), _p(moduli), _a(a), _b(b) {};

void Field::print(PrintSettings &psettings){
    if(psettings.range==0)
        psettings.range=size();
    switch(psettings.printmode){
        case PrintSettings::PrintMode::Dec:
        printDec(psettings);break;
        case PrintSettings::PrintMode::Hex:
        printHex(psettings); break;
        case PrintSettings::PrintMode::Char:
        printChar(psettings);break;
    }
}

void Field::printDec(PrintSettings &psettings){
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << ((getElement(i)%psettings.subfield)+psettings.post_offset) << " ";
    std::cout << (psettings.range==size()?"":"...") << std::endl;
}

void Field::printHex(PrintSettings &psettings){
    std::cout << std::hex << std::setw(2) << std::setfill('0');
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << ((getElement(i)%psettings.subfield)+psettings.post_offset) << " ";
    std::cout << (psettings.range==size()?"":"...") << std::dec << std::endl;
}

void Field::printChar(PrintSettings &psettings){
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << (uint8_t)((getElement(i)%psettings.subfield)+psettings.post_offset) << " ";
    std::cout << (psettings.range==size()?"":"...")<< std::endl;
}

void Field::printElementFieldEquation(gmp::mpz_int index){
    std::cout << _a << " * " << _g << "^"<< index << " + " << _b << "\t";
}

void Field::printElementFieldEquationGXPrecomputed(gmp::mpz_int gx){
    std::cout << _a << " * " << gx << " + " << _b << std::endl;
}

void Field::printGeneralFieldEquation(){
    std::cout << _a << " * " << _g << "^x + " << _b << std::endl;
}

bool Field::containsAt(gmp::mpz_int index, std::vector<gmp::mpz_int> &elements){
    bool match = true;
    for (gmp::mpz_int i = index; i < elements.size()+index; i++)
        if (elements[(size_t)(i-index)] != getElement(i))
            match = false;
    return match;
}
