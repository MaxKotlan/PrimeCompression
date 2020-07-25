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
    for(pt::ptree::value_type &action : _tree.get_child("searchsettings.actions")) {
        std::string re = action.second.get<std::string>("name");
        _actions.push_back(ActionFactory::getAction(re));
        std::cout << re << std::endl;
        //_actions.push_back(new )
    }
}