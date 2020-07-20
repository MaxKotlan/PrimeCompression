#include "../../element.h"

int main(){
    
    uint64_t p = 17;
    Element<uint64_t> A(10,p), B(20,p), C(0);
    C = A + B; 
    std::cout << A << " + " << B << " ≡ " << C << " mod " << p << std::endl;
    std::cout << "A=" << A <<"; -A=" << -A << std::endl;
    //std::cout << C << std::endl;
    C = B-A;
    std::cout << C << std::endl;

}