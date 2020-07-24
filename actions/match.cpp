#include "match.h"

void executematch(SearchState& state, const Action& act){
    for (Target &targ : state.searchsettings.targets){
        if (state.fd.containsAt(state.searchsettings.index, targ.data, state.searchsettings.printsettings.subfield)){
            if(state.searchsettings.printmatches){
                act.PrintInfo();
                std::cout << "Found at: ";
                state.fd.printElementFieldEquation(state.searchsettings.index);
                state.fd.print(state.searchsettings.printsettings);
            }
            if (targ.halt)
                exit(0);
        }
    }
}

const Action act_match{
    .id=8375887,
    .act=&executematch
};
