#pragma once
#include "field.h"
#include "fast_integer_exponentiation.h"

template <class T>
class FieldSearch{
    public:
        FieldSearch(T generator, T moduli) : _f(generator, moduli) { }
        void solutions(size_t index, T congruent);
        void printAllCoefficentCombinationsForSolution(size_t _index, uint64_t element);
        void printAllSolutionsUntil(size_t index, T element, size_t max);
        void search(std::vector<T> &elements);

    private:
        Field<T> _f;
};

template <class T>
void FieldSearch<T>::printAllCoefficentCombinationsForSolution(size_t index, uint64_t congruent){
    T _gx = powermod(_f.getGenerator(), index, _f.getModuli());
    for (uint64_t i = 0; i*_gx <= congruent; i++){
        _f.setA(i);
        _f.setB(congruent-i*_gx);
        _f.printElementFieldEquation(index);
        _f.printChar(17);
        //_f.printElementFieldEquationGXPrecomputed(_gx);
        //_f.printFieldEquation();
    }
}

template <class T>
void FieldSearch<T>::printAllSolutionsUntil(size_t index, T element, size_t max){
    for (size_t i = 0; i < max; i++)
        printAllCoefficentCombinationsForSolution(index, _f.getModuli()*i+element);
}

template <class T>
void FieldSearch<T>::solutions(size_t index, T element) {
    for (int i = 0; i < 10; i++)
        std::cout << (_f.getModuli()*i+element)*(_f.getModuli()*i) << ((i!=9)?", ":"...");
    std::cout << std::endl;
};