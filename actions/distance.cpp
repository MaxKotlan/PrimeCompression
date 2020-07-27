#include "distance.h"

namespace pt = boost::property_tree;

void Distance::operator()(SearchState &state){
    uint8_t check = (uint8_t)(state.fd.getElement(state.searchsettings.index+1)%state.searchsettings.printsettings.subfield);
    //if (locations[check-'A'].size() < depth)
    //if (locations[check].size() > 0)
    //    avar = state.fd.getA()-locations[check].back();
    //else
    gmp::mpz_int avar = state.fd.getA();
    //std::vector<gmp::mpz_int> &letter = locations[check];
    locations[check].push_back(avar);
    if (state.fd.getA()%_pollingrate == 0){
        for (int i = 0; i < locations.size(); i++){
            std::cout << locations[i].size() << "\t" << (uint8_t)(i+'A') << ": ";
            for (int j = (locations[i].size()-(uint64_t)printsize); j < locations[i].size(); j++){
                gmp::mpz_int res;
                if (j == 0)
                    res = locations[i][0];
                else
                    res = (locations[i][j] - locations[i][j-1]);
                std::cout << res << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

void Distance::load(pt::ptree &_tree){
    Action::load(_tree);
    printsize = _tree.get<gmp::mpz_int>("printsize", 10);

}

/*
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
*/