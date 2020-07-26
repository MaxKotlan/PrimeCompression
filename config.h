#pragma once 
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <string>
#include <set>
#include <exception>
#include <iostream>
#include <vector>
#include "actions.h"
#include "field.h"
#include "searchsettings.h"
namespace pt = boost::property_tree;

class Config{
    public:
        Config(std::string configfile);
        ~Config();
    protected:
        void ReadField();
        void ReadSearchSettings();
        void ReadPrintSettings();
    public:
        std::string _filename;
        FieldParameters _fieldparams;
        SearchSettings  _searchsettings;
        pt::ptree _tree;
        std::vector<Action*> _actions;
};