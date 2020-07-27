
#pragma once
#include <thread>
#include "fieldsearch.h"

void SearchThread(uint64_t threadid, uint64_t threadcount, Config conf){
    FieldSearch(conf).Search(threadid, threadcount);
}

class Search{
    public:
        Search(Config& conf) : _threads(conf.getThreadSettings().threadcount){
            for (uint64_t i = 0; i < _threads.size(); i++)
                _threads[i] = new std::thread(&SearchThread, i, _threads.size(),  conf);
            for (uint64_t i = 0; i < _threads.size(); i++)
                _threads[i]->join();
        }

        ~Search(){
            for (auto &thread : _threads)
                delete thread;
        }
    protected:
        std::vector<std::thread*> _threads;
};