#include <iostream>
#include <vector>
#include "fieldsearch.h"
#include "printallsums.h"

int main(int argc, char** argv){
    uint32_t p = 17;
    uint32_t c = 3;
    uint32_t g = 1;
    std::cout << "Find all values of a and b such that a + b ≡ c mod p" << std::endl;
    std::cout << "Let c = " << c << std::endl;
    std::cout << "Let p = " << p << std::endl;
    std::cout << "Let d = a + b" << std::endl;
    std::cout << "d ≡ ";
    for (int i = 0; i < 10; i++)
        std::cout << p*i+c << ((i!=9)?", ":"...");
    std::cout << std::endl; 
    for (uint32_t i = 0; i < 10; i++){
        printallsums(p*i+c, g);
        std::cout << std::endl << std::endl;
    }

    std::vector<uint8_t> inputdata{'M', 'a', 'x'};
    FieldSearch fs(&inputdata);
}