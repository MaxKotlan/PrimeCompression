#include "match.h"

namespace pt = boost::property_tree;

void Match::operator()(SearchState &ss){

    for (Target &targ : ss.searchsettings.targets){
        if (ss.fd.containsAt(ss.searchsettings.index, targ.data, ss.searchsettings.printsettings.subfield)){
            if(ss.searchsettings.printmatches){
                Action::time();
                std::cout << "Found at: ";
                ss.fd.printElementFieldEquation(ss.searchsettings.index);
                ss.fd.print(ss.searchsettings.printsettings);
            }
            if (targ.halt)
                exit(0);
        }
    }

    /*
    if (ss.fd.getA()%_pollingrate==0 && ss.searchsettings.printnonmatches){
        time();
        switch(ss.searchsettings.printsettings.equationformat) {
            case PrintSettings::EquationFormat::GX: ss.fd.printElementFieldEquationGXPrecomputed(ss.gx); break; 
            case PrintSettings::GPowerX:            ss.fd.printElementFieldEquation(ss.searchsettings.index); break;
        }
        ss.fd.print(ss.searchsettings.printsettings);
    }*/
}

void Match::load(pt::ptree &_tree){
    Action::load(_tree);

}

/*
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
};*/
