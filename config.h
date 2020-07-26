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
        inline const FieldParameters& getFieldParameters() const { return _fieldparams;    };
        inline const SearchSettings&  getSearchSettings()  const { return _searchsettings; };
        inline const PrintSettings&   getPrintSettings()   const { return _printsettings;  };
        inline const std::vector<Action*>&   getActions()  const { return _actions;};

    private:
        void ReadField();
        void ReadSearchSettings();
        void ReadPrintSettings();

        std::string     _filename;
        FieldParameters _fieldparams;
        SearchSettings  _searchsettings;
        PrintSettings   _printsettings;
        pt::ptree       _tree;
        std::vector<Action*> _actions;
};