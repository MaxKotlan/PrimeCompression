#include "config.h"
#include "actions.h"

Config::Config(std::string filename) : _filename(filename){
    pt::read_json(_filename, _tree);
    ReadField();
    ReadSearchSettings();
    ReadPrintSettings();
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
    _searchsettings.a_offset = _tree.get<gmp::mpz_int>("searchsettings.a_offset", _searchsettings.a_offset);
    _searchsettings.index    = _tree.get<gmp::mpz_int>("searchsettings.index",       _searchsettings.index);
    _searchsettings.initalelement = _tree.get<std::string>("searchsettings.initalelement")[0];
    _searchsettings.initalelementnormalize = _tree.get<bool>("searchsettings.initalelementnormalize", _searchsettings.initalelementnormalize);

    std::cout << "Enabled Actions: ";
    for(pt::ptree::value_type &actionprop : _tree.get_child("searchsettings.actions")) {
        auto &action = actionprop.second;
        if(action.get<bool>("enabled", true)){
            std::string re = action.get<std::string>("name");
            Action* act = ActionFactory::getAction(re);
            act->load(action);
            _actions.push_back(act);
            std::cout << re << ", ";
        }
    }
    std::cout << std::endl;
}

void Config::ReadPrintSettings(){
    _printsettings.range       = _tree.get<gmp::mpz_int>("printsettings.range", _printsettings.range);
    _printsettings.offset      = _tree.get<gmp::mpz_int>("printsettings.offset", _printsettings.offset);
    _printsettings.post_offset = _tree.get<gmp::mpz_int>("printsettings.post_offset", _printsettings.post_offset);
    _printsettings.subfield    = _tree.get<gmp::mpz_int>("printsettings.subfield", _printsettings.subfield);
    _printsettings.equationformat = static_cast<PrintSettings::EquationFormat>(_tree.get<uint8_t>("printsettings.equationformat"));
    _printsettings.printmode      = static_cast<PrintSettings::PrintMode>(_tree.get<uint8_t>("printsettings.printmode"));
}