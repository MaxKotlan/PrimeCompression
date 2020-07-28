#include "../config.h"
#include "print.h"

namespace pt = boost::property_tree;

void Print::operator()(SearchState &ss){
    if (ss.fd.getA()%_pollingrate==0){
        time();
        switch(_conf->getPrintSettings().equationformat) {
            case PrintSettings::EquationFormat::GX: ss.fd.printElementFieldEquationGXPrecomputed(ss.gx); break; 
            case PrintSettings::GPowerX:            ss.fd.printElementFieldEquation(_conf->getSearchSettings().index); break;
        }
        ss.fd.print(_conf->getPrintSettings());
    }
}

Action* Print::clone(){ return new Print(*this); }

void Print::load(pt::ptree &_tree){
    Action::load(_tree);

}