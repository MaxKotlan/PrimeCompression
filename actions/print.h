#pragma once
#include "action.h"

class Print : public Action{
    public:
        Print(){};
        void operator()(SearchState &s);
        void load(boost::property_tree::ptree &_tree);
        Action* clone();
};