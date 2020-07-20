#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "fast_integer_exponentiation.h"

template <class T>
struct PrintSettings{
    T range=0;
    T offset=0;
    enum PrintMode{
        Dec,
        Hex,
        Char
    } printmode=PrintMode::Dec;
};

template <class T>
class Field{
    public:
        Field(T generator, T moduli);
        Field(T generator, T moduli, T a, T b);

        void inline setCoefficents(T a, T b) { _a = a; _b = b; }
        T inline getModuli() { return _p; };
        T inline getGenerator() { return _g; };
        T inline getA() { return _a; };
        T inline getB() { return _b; };
        void inline setA(T a) {_a = a;};
        void inline setB(T b) {_b = b;};
        size_t inline size() { return _p - 1; };
        void print(PrintSettings<T> psettings);
        void print();
        void print(T offset, size_t range);
        void printHex();
        void printHex(T offset, size_t range);
        void printChar();
        void printChar(T offset, size_t range);
        bool containsAt(size_t index, std::vector<T> &elements);
        T inline getElement(T index) { return ((_a*power_mod(_g, index,_p)+_b)%_p); };
        void printElementFieldEquation(size_t index);
        void printElementFieldEquationGXPrecomputed(T gx);
        void printGeneralFieldEquation();

    private:
        /*Coefficents used to modify standard exponential fields*/
        T _a;
        T _b;

        /*Generator and moduli*/
        T _g;
        T _p;
};

template <class T>
Field<T>::Field(T generator, T moduli) : _g(generator), _p(moduli), _a(1), _b(0) {};

template <class T>
Field<T>::Field(T generator, T moduli, T a, T b) : _g(generator), _p(moduli), _a(a), _b(b) {};

template <class T>
void Field<T>::print(PrintSettings<T> psettings){
    if(psettings.range==0)
        psettings.range=size();
    switch(psettings.printmode){
        case PrintSettings<T>::PrintMode::Dec:
        print(psettings.offset, psettings.range);break;
        case PrintSettings<T>::PrintMode::Hex:
        printHex(psettings.offset, psettings.range); break;
        case PrintSettings<T>::PrintMode::Char:
        printChar(psettings.offset, psettings.range);break;
    }
}


template <class T>
void Field<T>::print(){
    print(0,size());
}

template <class T>
void Field<T>::printHex(){
    printHex(0,size());
}

template <class T>
void Field<T>::printChar(){
    printChar(0,size());
}

template <class T>
void Field<T>::print(T offset, size_t range){
    for (size_t i = offset; i < offset+range; i++)
        std::cout << getElement(i) << " ";
    std::cout << (range==size()?"":"...") << std::endl;
}

template <class T>
void Field<T>::printHex(T offset, size_t range){
    std::cout << std::hex << std::setw(2) << std::setfill('0');
    for (size_t i = offset; i < offset+range; i++)
        std::cout << getElement(i) << " ";
    std::cout << (range==size()?"":"...") << std::dec << std::endl;
}

template <class T>
void Field<T>::printChar(T offset, size_t range){
    for (size_t i = offset; i < offset+range; i++)
        std::cout << (uint8_t)getElement(i) << " ";
    std::cout << (range==size()?"":"...")<< std::endl;
}

template <class T>
void Field<T>::printElementFieldEquation(size_t index){
    std::cout << _a << " * " << _g << "^"<< index << " + " << _b << "\t";
}

template <class T>
void Field<T>::printElementFieldEquationGXPrecomputed(T gx){
    std::cout << _a << " * " << gx << " + " << _b << std::endl;
}

template <class T>
void Field<T>::printGeneralFieldEquation(){
    std::cout << _a << " * " << _g << "^x + " << _b << std::endl;
}


template <class T>
bool Field<T>::containsAt(size_t index, std::vector<T> &elements){
    bool match = true;
    for (size_t i = index; i < elements.size()+index; i++)
        if (elements[i-index] != getElement(i))
            match = false;
    return match;
}
