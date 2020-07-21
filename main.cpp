#include <iostream>
#include "fieldsearch.h"

void testlarge(){
    FieldSearch<uint64_t> fs(3, (1 << 31)-1);
    fs.setPrintSettings({
        .range=30,
        .offset=0,
        .post_offset='A',
        .subfield=26,
        .printmode=PrintSettings<uint64_t>::PrintMode::Char   
    });
    fs.printAllEquations(0, 'M'-'A');
}

void testsmall(){
    FieldSearch<uint64_t> fs(3, 17);
    fs.printAllEquations(2, 7);
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
    //std::cout << 'M'-'A' << std::endl;
    //FieldSearch<uint64_t>(3, (1 << 31)-1).printAllEquations(2, 'M');
    testlarge();
    //FieldSearch<uint64_t>(3, 17).printAllEquations(2, 7);//printAllCoefficentCombinationsForSolution(1, 20);

    //Field<uint64_t> f(3, 17);
    //std::cout << std::endl;
    //f.print();
    return 0;
}