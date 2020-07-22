#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <boost/multiprecision/gmp.hpp>

namespace gmp = boost::multiprecision;

struct PrintSettings{
    gmp::mpz_int range=0;
    gmp::mpz_int offset=0;
    gmp::mpz_int post_offset=0;
    gmp::mpz_int subfield=256;
    enum EquationFormat{
        GX,
        GPowerX
    } equationformat=EquationFormat::GX;
    enum PrintMode{
        Dec,
        Hex,
        Char
    } printmode=PrintMode::Dec;
};

struct FieldParameters{
    gmp::mpz_int generator=1;
    gmp::mpz_int moduli=1;
    gmp::mpz_int coefficenta=1;
    gmp::mpz_int coefficentb=0;
};

class Field{
    public:
        Field(FieldParameters fieldparameters);

        void inline setCoefficents(gmp::mpz_int &a, gmp::mpz_int &b) { _a = a; _b = b; }
        gmp::mpz_int inline getModuli() { return _p; };
        gmp::mpz_int inline getGenerator() { return _g; };
        gmp::mpz_int inline getA() { return _a; };
        gmp::mpz_int inline getB() { return _b; };
        void inline setA(gmp::mpz_int &a) {_a = a;};
        void inline setB(gmp::mpz_int &b) {_b = b;};
        gmp::mpz_int inline size() { return _p - 1; };
        void print(PrintSettings &psettings);
        bool containsAt(gmp::mpz_int &index, std::vector<gmp::mpz_int> &elements);
        gmp::mpz_int getElement(gmp::mpz_int index) {
            gmp::mpz_int k = gmp::powm(_g, index,_p); 
            return ((_a * k+_b)%_p); 
        };
        void printElementFieldEquation(gmp::mpz_int &index);
        void printElementFieldEquationGXPrecomputed(gmp::mpz_int &gx);
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