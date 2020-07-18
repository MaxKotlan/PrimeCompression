#include <iostream>
#include "field.h"

int main(int argc, char** argv){
    Field<uint64_t> f(3, 17);
    f.print();
}