#include <iostream>
#include <vector>
#include "fieldsearch.h"
#include "printallsums.h"

int main(int argc, char** argv){
    uint32_t p = 17;//(1 << 31)-1;
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
    //std::cout << "e ≡ ";
    //for (int i = 0; i < 10; i++)
    //    std::cout << p*i+c+1 << ((i!=9)?", ":"...");
    //std::cout << std::endl; 

    for (uint32_t i = 0; i < 2; i++){
        std::cout << "--" << c << "--" << std::endl;
        printallsums(p*i+c, 1);
        std::cout << std::endl << std::endl;
        std::cout << "--" << c+1 << "--" << std::endl;
        printallsums(p*i+c+1, 5);
        std::cout << std::endl << std::endl;
    }

    std::vector<uint8_t> inputdata{ 'M', 'b'};
    FieldSearch fs(&inputdata);
}