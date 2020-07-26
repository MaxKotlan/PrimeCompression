#pragma once
#include "action.h"

class Match : public Action{
    public:
        Match(){};
        void operator()(SearchState &s);
        void load(boost::property_tree::ptree &_tree);
    private:
        std::vector<Target> _targets;
};