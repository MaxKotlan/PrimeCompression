#include "../fast_integer_exponentiation.h"

int main(){

    for (uint16_t i = 0; i != 256; i++){
    uint64_t c=(-1)*i; uint64_t d=15;
        {
            uint64_t a = c;
            uint64_t b = d;
            std::cout << -1*(int32_t)i << " " << b << "[ ";
            std::cout << (uint64_t)mod(a, b) << ", ";
        }
        {
            uint32_t a = c;
            uint32_t b = d;
            std::cout << (uint64_t)mod(a, b) << ", ";
        }
        {
            uint16_t a = c;
            uint16_t b = d;
            std::cout << (uint64_t)mod(a, b) << ", ";
        }
        {
            uint8_t a = c;
            uint8_t b = d;
            std::cout << (uint64_t)mod(a, b) << "] ";
        }
        std::cout << std::endl;
    }
}