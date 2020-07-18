#pragma once
#include <iostream>
#include <vector>
#include "fast_integer_exponentiation.h"

template <class T>
class Field{
    public:
        Field(T generator, T moduli);
        void print();
        void print(uint64_t range);
        uint64_t size();
        bool containsAt(uint64_t index, std::vector<T> &elements);
    private:
        T _g;
        T _p;
};

template <class T>
Field<T>::Field(T generator, T moduli) : _g(generator), _p(moduli) {};

template <class T>
void Field<T>::print(){
    print(size());
}

template <class T>
void Field<T>::print(uint64_t range){
    for (uint64_t i = 0; i < range; i++)
        std::cout << powermod(_g, i, _p) << " ";
    std::cout << std::endl;
}

template <class T>
uint64_t Field<T>::size(){ return _p - 1; }

template <class T>
bool Field<T>::containsAt(uint64_t index, std::vector<T> &elements){
    bool match = true;
    for (uint64_t i = index; i < elements.size()+index; i++)
        if (elements[i-index] != (T)powermod(_g, i, _p))
            match = false;
    return match;
}
