#pragma once
#include "action.h"

class Distance : public Action{
    public:
        Distance() {};
        void operator()(SearchState &s);
        void load(boost::property_tree::ptree &_tree);
        
};