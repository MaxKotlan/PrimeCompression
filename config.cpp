#include "config.h"

Config::Config(std::string filename) : _filename(filename){
    pt::read_json(_filename, _tree);
    ReadField();
    ReadSearchSettings();
}

void Config::ReadField(){
    _fieldparams.generator = _tree.get<gmp::mpz_int>("field.generator");
    _fieldparams.moduli = _tree.get<gmp::mpz_int>("field.moduli");
}

void Config::ReadSearchSettings(){
    _searchsettings.a_offset = _tree.get<gmp::mpz_int>("searchsettings.a_offset");
    _searchsettings.index    = _tree.get<gmp::mpz_int>("searchsettings.index");

}