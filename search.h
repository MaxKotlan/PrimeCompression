
#pragma once
#include <thread>
#include "searchthread.h"

class Search{
    public:
        Search(Config* conf);
        ~Search();
        
    protected:
        std::vector<std::thread*> _threads;
};