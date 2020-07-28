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

        void inline setCoefficents(const gmp::mpz_int &a,const  gmp::mpz_int &b) { _a = a; _b = b; }
        gmp::mpz_int inline getModuli() const { return _p; };
        gmp::mpz_int inline getGenerator() const { return _g; };
        gmp::mpz_int inline getA() const { return _a; };
        gmp::mpz_int inline getB() const { return _b; };
        void inline setA(const gmp::mpz_int &a) {_a = a;};
        void inline setB(const gmp::mpz_int &b) {_b = b;};
        gmp::mpz_int inline size() const { return _p - 1; };
        void print(const PrintSettings &psettings) const;
        bool containsAt(const gmp::mpz_int &index, const std::vector<gmp::mpz_int> &elements, const gmp::mpz_int &subfield) const;
        gmp::mpz_int getElement(const gmp::mpz_int index) const {
            gmp::mpz_int k = gmp::powm(_g, index,_p); 
            return ((_a * k+_b)%_p); 
        };
        void printElementFieldEquation(const gmp::mpz_int &index) const;
        void printElementFieldEquationGXPrecomputed(const gmp::mpz_int &gx) const;
        void printGeneralFieldEquation() const;

    protected:
        void printDec(const PrintSettings &psettings)  const;
        void printHex(const PrintSettings &psettings)  const;
        void printChar(const PrintSettings &psettings) const;

    private:
        /*Coefficents used to modify standard exponential fields*/
        gmp::mpz_int _a;
        gmp::mpz_int _b;

        /*Generator and moduli*/
        gmp::mpz_int _g;
        gmp::mpz_int _p;
};