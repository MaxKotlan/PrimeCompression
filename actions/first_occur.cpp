#include "first_occur.h"

void executefirstoccur(SearchState& state, const Action& act){
    static std::vector<gmp::mpz_int> firstfound(26, 0);
    static gmp::mpz_int foundcount = 0;

    uint8_t check = (uint8_t)(state.fd.getElement(state.searchsettings.index+1)%state.searchsettings.printsettings.subfield);

    if (!firstfound[check]){
        firstfound[check] = state.fd.getA();
        foundcount++;
    }

    if (foundcount == 27){
        for (int i = 0; i < firstfound.size(); i++)
            std::cout << (uint8_t)('A'+i) << ": " << firstfound[i] << ", ";
        exit(-1);
    }

}

const Action act_first_occur{
    .id=1654657,
    .act=&executefirstoccur
};
