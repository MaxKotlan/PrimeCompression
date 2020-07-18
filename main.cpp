#include <iostream>
#include "fieldsearch.h"

int main(int argc, char** argv){
    FieldSearch<uint64_t>((1 << 30)-10, (1 << 31)-1).printAllSolutionsUntil(1, 'M', (1 << 31)-1);//printAllCoefficentCombinationsForSolution(1, 20);
    //FieldSearch<uint64_t>(3, 17).solutions(0, 1);

    //Field<uint64_t> f(3, 17);
    //std::cout << std::endl;
    //f.print();
}