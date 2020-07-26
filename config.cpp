#include "config.h"
#include "actions.h"

Config::Config(std::string filename) : _filename(filename){
    pt::read_json(_filename, _tree);
    ReadField();
    ReadSearchSettings();
}

Config::~Config(){
    for (auto &action : _actions)
        delete action;
}

void Config::ReadField(){
    _fieldparams.generator = _tree.get<gmp::mpz_int>("field.generator");
    _fieldparams.moduli = _tree.get<gmp::mpz_int>("field.moduli");
}

void Config::ReadSearchSettings(){
    _searchsettings.a_offset = _tree.get<gmp::mpz_int>("searchsettings.a_offset");
    _searchsettings.index    = _tree.get<gmp::mpz_int>("searchsettings.index");
    for(pt::ptree::value_type &actionprop : _tree.get_child("searchsettings.actions")) {
        auto &action = actionprop.second;
        if(action.get<bool>("enabled", true)){

            std::string re = action.get<std::string>("name");
            Action* act = ActionFactory::getAction(re);
            act->load(action);
            _actions.push_back(act);
            std::cout << "Enabled Action: " << re << std::endl;
        }
    }
}