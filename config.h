#pragma once 
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
#include "field.h"
#include "fieldsearch.h"
namespace pt = boost::property_tree;

class Config{
    public:
        Config(std::string configfile);
    protected:
        void ReadField();
        void ReadSearchSettings();
        void ReadPrintSettings();
    private:
        std::string _filename;
        FieldParameters _fieldparams;
        SearchSettings  _searchsettings;
        pt::ptree _tree;
};