#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "fast_integer_exponentiation.h"

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
        void print();
        void print(size_t range);
        void printHex();
        void printHex(size_t range);
        void printChar();
        void printChar(size_t range);
        bool containsAt(size_t index, std::vector<T> &elements);
        T inline getElement(T index) { return (_a*power(_g, index)+_b)%_p; };
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
void Field<T>::print(){
    print(size());
}

template <class T>
void Field<T>::printHex(){
    printHex(size());
}

template <class T>
void Field<T>::printChar(){
    printChar(size());
}

template <class T>
void Field<T>::print(size_t range){
    for (size_t i = 0; i < range; i++)
        std::cout << getElement(i) << " ";
    std::cout << std::endl;
}

template <class T>
void Field<T>::printHex(size_t range){
    std::cout << std::hex << std::setw(2) << std::setfill('0');
    for (size_t i = 0; i < range; i++)
        std::cout << getElement(i) << " ";
    std::cout << std::dec << std::endl;
}

template <class T>
void Field<T>::printChar(size_t range){
    for (size_t i = 0; i < range; i++)
        std::cout << (uint8_t)getElement(i) << " ";
    std::cout << std::endl;
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
        if (elements[i-index] != (T)getElement(i))
            match = false;
    return match;
}
