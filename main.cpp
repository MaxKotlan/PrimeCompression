#include <iostream>

struct Result{
    uint32_t a;
    uint32_t b;
    uint32_t g;
    void print(std::ostream &out) const{
        out << a << "*" << g << "+" << b;
    }
};

std::ostream &operator<<(std::ostream &out, const Result &obj) {
    obj.print(out);
    return out;
}


void printallsums(uint32_t s, uint32_t g){
    Result r;
    for (uint32_t i = g-1; i*g <= s; i++){
        r.a=i;
        r.b=s-i*g;
        r.g=g;
        std::cout << i << ": " << r << std::endl;
    }
}

int main(int argc, char** argv){
    uint32_t p = 17;
    uint32_t c = 3;
    uint32_t g = 2;
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
}