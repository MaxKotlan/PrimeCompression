#pragma once
#include "field.h"
#include "fast_integer_exponentiation.h"

template <class T>
class FieldSearch{
    public:
        FieldSearch(T generator, T moduli) : _f(generator, moduli) { }
        void solutions(size_t index, T congruent);
        void printAllEquations(size_t index, T element);
        void printAllCoefficentCombinationsForSolution(size_t _index, uint64_t element);
        void printAllSolutionsUntil(size_t index, T element, size_t max);
        void search(std::vector<T> &elements);

    private:
        uint64_t pollingrate = 1;
        Field<T> _f;
};

template <class T>
void FieldSearch<T>::printAllEquations(size_t index, T element){
    uint64_t s = (_f.getModuli()*(_f.getModuli()-1)+element);
    //uint64_t s = element-1;
    //s %= _f.getModuli();
    //std::cout << s;
    PrintSettings<T> psettings{
        .range=30,
        .offset=index,
        .printmode=PrintSettings<T>::PrintMode::Char
    };
    std::vector<T> halt{ 'M', 'A' };
    uint64_t p = _f.getModuli();
    uint64_t _gx = powermod(_f.getGenerator(), index, _f.getModuli());
    for (uint64_t a = 0; a < _f.getModuli(); a++){
        _f.setA(a);
        uint64_t b = mod(element - mod(_gx*a,p),p);
        _f.setB(b);
        if (a%pollingrate==0){
            _f.printElementFieldEquation(index);
            _f.print(psettings);
        }
        //static uint64_t prev = 0;
        //if (_f.containsAt(index, halt)){
        //    std::cout << "Found at A: " << a << std::endl;
        //    _f.printElementFieldEquation(index);
            //_f.printChar(10);
            //static uint64_t count = 0;
            //count++;
            //if (prev != 0 && a-prev != 13){
            //    std::cout << "DIVERGES! a:" << a << " : " << a-prev << std::endl;
                //exit(-1);
            //}
            //prev = a;
            //if (count == 10)
            //    exit(-1);
        //}
    }
    std::cout << "Search Complete" << std::endl;
}

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