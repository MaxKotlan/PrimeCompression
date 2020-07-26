#pragma once
#include <boost/property_tree/ptree.hpp>
#include <chrono>
#include "../searchsettings.h"

struct SearchState{
    SearchSettings& searchsettings;
    Field& fd;
    gmp::mpz_int gx;
    gmp::mpz_int  s;
};


class Action{
    public:
        Action() : _prev_time(std::chrono::high_resolution_clock::now()){};
        virtual void operator()(SearchState &s)=0;
        //virtual void load(boost::property_tree::ptree &_tree)=0;
        virtual void load(boost::property_tree::ptree &_tree){
            _pollingrate = _tree.get<gmp::mpz_int>("pollingrate", _pollingrate);
        }
        void time(){
            auto now = std::chrono::high_resolution_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(now - _prev_time).count() << "ms\t";
            _prev_time = now;
        }
    protected:
        gmp::mpz_int _pollingrate=1;
        std::chrono::_V2::system_clock::time_point _prev_time;
};