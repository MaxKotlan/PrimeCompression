#include "../config.h"
#include "distance.h"
#include <mutex>
#include <algorithm>
#include <functional>

namespace pt = boost::property_tree;

std::mutex mtx;

void Distance::operator()(SearchState &state){
    uint8_t check = (uint8_t)(state.fd.getElement(_conf->getSearchSettings().index+checkoffset)%_conf->getPrintSettings().subfield);
    
    gmp::mpz_int avar = state.fd.getA();
    {
        std::lock_guard<std::mutex> printGuard(mtx);
        locations[check].push_back(avar);
        std::push_heap(locations[check].begin(), locations[check].end(), std::greater<gmp::mpz_int>());
    
        if (state.fd.getA()%_pollingrate == 0){
            for (int i = 0; i < locations.size(); i++){
                std::cout << locations[i].size() << "\t" << (uint8_t)(i+'A') << ": ";
                std::vector<gmp::mpz_int>lol = locations[i];
                gmp::mpz_int prev = 0;
                while (lol.size() > 0){
                    std::cout << std::fixed << std::setw(2) << lol.front()-prev << " ";
                    prev = lol.front();
                    std::pop_heap(lol.begin(), lol.end(), std::greater<gmp::mpz_int>());
                    lol.pop_back();
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

Action* Distance::clone(){ return new Distance(*this); }

void Distance::load(pt::ptree &_tree){
    Action::load(_tree);
    printsize   = _tree.get<gmp::mpz_int>("printsize", 10);
    checkoffset = _tree.get<gmp::mpz_int>("checkoffset", checkoffset);

}