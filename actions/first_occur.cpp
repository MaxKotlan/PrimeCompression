#include "first_occur.h"

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
    halt = _tree.get<bool>("halt", false);
}