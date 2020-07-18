#pragma once
#include "field.h"

template <class T>
class FieldSearch{
    public:
        FieldSearch(T generator, T moduli) : _f(generator, moduli) { }
        void solutions(size_t index, T element);
        void search(std::vector<T> &elements);

    private:
        Field<T> _f;
};

template <class T>
void FieldSearch<T>::solutions(size_t index, T elements) {
    for (int i = 0; i < 10; i++)
        std::cout << _f.getModuli()*i+3 << ((i!=9)?", ":"..."); 
};