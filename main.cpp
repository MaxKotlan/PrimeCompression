#include <iostream>
#include "fieldsearch.h"

int main(int argc, char** argv){
    //FieldSearch<uint64_t> f(3, 17);
    //f.solutions(0, 1);
    Field<uint64_t> f(3, 17);
    std::cout << std::endl;
    f.print();
}