#include "../config.h"
#include "match.h"

namespace pt = boost::property_tree;

void Match::operator()(SearchState &ss){

    for (Target &targ : _targets){
        if (ss.fd.containsAt(_conf->getSearchSettings().index, targ.data, _conf->getPrintSettings().subfield)){
            Action::time();
            std::cout << "Found at: ";
            ss.fd.printElementFieldEquation(_conf->getSearchSettings().index);
            ss.fd.print(_conf->getPrintSettings());
            if (targ.halt)
                exit(0);
        }
    }
}

void Match::load(pt::ptree &_tree){
    Action::load(_tree);
    for (auto &targetprop : _tree.get_child("targets")){
        auto &target = targetprop.second;
        Target t;
        std::string data = target.get<std::string>("data");
        for (uint8_t bte : data)
            if (bte != '\0')
                t.data.push_back(bte-'A');
        t.normalize=target.get<bool>("normalize",t.normalize);
        t.halt=target.get<bool>("halt",t.halt);
        _targets.push_back(t);
    }
}