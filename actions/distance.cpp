#include "distance.h"

namespace pt = boost::property_tree;

void FirstOccur::operator()(SearchState &state){
    uint8_t check = (uint8_t)(state.fd.getElement(state.searchsettings.index+1)%state.searchsettings.printsettings.subfield);

    if (!foundat[check]){
        foundat[check] = state.fd.getA();
        foundcount++;
    }

    if (foundcount == 27){
        for (int i = 0; i < foundat.size(); i++)
            std::cout << (uint8_t)('A'+i) << ": " << foundat[i] << ", ";
        std::cout << std::endl;
        if (halt)
            exit(-1);
    }
}

void FirstOccur::load(pt::ptree &_tree){
    Action::load(_tree);

}

void executedistance(SearchState& state, const Action& act){
    static std::vector<gmp::mpz_int> distance;
    static gmp::mpz_int aprev = 0;

    uint8_t check = (uint8_t)(state.fd.getElement(state.searchsettings.index+1)%state.searchsettings.printsettings.subfield);

    if (check == 'A'-'A'){
        distance.push_back(state.fd.getA()-aprev);
        aprev = state.fd.getA();
    }

    if (state.fd.getA() == (state.fd.getModuli()-1) || distance.size() > 100){
        act.PrintInfo();
        for (int i = 0; i < distance.size(); i++)
            std::cout << distance[i] << ", ";
        std::cout << std::endl;
        exit(0);
    }
}

const Action act_distance{
    .id=2305805,
    .act=&executedistance
};
