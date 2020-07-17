#pragma once

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