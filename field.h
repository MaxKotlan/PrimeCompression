#pragma once
#include <iostream>
#include <vector>
#include "fast_integer_exponentiation.h"

template <class T>
class Field{
    public:
        Field(T generator, T moduli);
        Field(T generator, T moduli, T a, T b);

        void inline setCoefficents(T a, T b) { _a = a; _b = b; }
        void inline setA(T a) {_a = a;};
        void inline setB(T b) {_b = b;};
        size_t inline size() { return _p - 1; };
        void print();
        void print(size_t range);
        bool containsAt(size_t index, std::vector<T> &elements);
        T inline getElement(T index) { return (_a*power(_g, index)+_b)%_p; };

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
void Field<T>::print(size_t range){
    for (size_t i = 0; i < range; i++)
        std::cout << getElement(i) << " ";
    std::cout << std::endl;
}

template <class T>
bool Field<T>::containsAt(size_t index, std::vector<T> &elements){
    bool match = true;
    for (size_t i = index; i < elements.size()+index; i++)
        if (elements[i-index] != (T)getElement(i))
            match = false;
    return match;
}
