#include <iostream>
#include "fieldsearch.h"

uint64_t mod(uint64_t a, uint64_t b){
    if (a < b) return a;
}

int main(int argc, char** argv){
    //FieldSearch<uint64_t>((1 << 30)-10, (1 << 31)-1).printAllEquations(1, 'M');//printAllCoefficentCombinationsForSolution(1, 20);
    //std::cout << (uint64_t)(-1)% << std::endl;
    //uint64_t primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    //for (auto p : primes){
    //    std::cout << p << ", " << std::endl;
    //}
    
    //std::cout << std::hex;
    //FieldSearch<uint16_t>(3, 7).printAllEquations(2, 3);//printAllCoefficentCombinationsForSolution(1, 20);
    /*for (int i = 0; i < 17-1; i++){
        std::cout << i << "----" << std::endl;
        FieldSearch<uint64_t>(3, 17).printAllEquations(i, 7);//printAllCoefficentCombinationsForSolution(1, 20);
        std::cout <<  std::endl;
    }*/

    FieldSearch<uint64_t>(14879879, (1 << 31)-1).printAllEquations(1, 'M');
    //FieldSearch<uint64_t>(3, 17).printAllEquations(2, 7);//printAllCoefficentCombinationsForSolution(1, 20);

    //Field<uint64_t> f(3, 17);
    //std::cout << std::endl;
    //f.print();
}