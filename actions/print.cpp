#include "print.h"

namespace pt = boost::property_tree;

Print::Print(){ 

}

void Print::operator()(SearchState &ss){
    if (ss.fd.getA()%ss.searchsettings.pollingrate==0 && ss.searchsettings.printnonmatches){
        //act.PrintInfo();
        switch(ss.searchsettings.printsettings.equationformat) {
            case PrintSettings::EquationFormat::GX: ss.fd.printElementFieldEquationGXPrecomputed(ss.gx); break; 
            case PrintSettings::GPowerX:            ss.fd.printElementFieldEquation(ss.searchsettings.index); break;
        }
        ss.fd.print(ss.searchsettings.printsettings);
    }
}

void Print::load(pt::ptree &_tree){

}

/*
void execute(SearchState& ss, const Action& act){
    if (ss.fd.getA()%ss.searchsettings.pollingrate==0 && ss.searchsettings.printnonmatches){
        act.PrintInfo();
        switch(ss.searchsettings.printsettings.equationformat) {
            case PrintSettings::EquationFormat::GX: ss.fd.printElementFieldEquationGXPrecomputed(ss.gx); break; 
            case PrintSettings::GPowerX:            ss.fd.printElementFieldEquation(ss.searchsettings.index); break;
        }
        ss.fd.print(ss.searchsettings.printsettings);
    }
}

const Action act_print{
    .id=7861867,
    .act=&execute
};*/