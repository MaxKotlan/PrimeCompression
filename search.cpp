#include "search.h"

void InitalizeSearchThread(uint64_t threadid, uint64_t threadcount, Config conf){
    SearchThread(conf).Search(threadid, threadcount);
}

Search::Search(Config& conf) : _threads(conf.getThreadSettings().threadcount){
    for (uint64_t i = 0; i < _threads.size(); i++)
        _threads[i] = new std::thread(&InitalizeSearchThread, i, _threads.size(),  conf);
    for (uint64_t i = 0; i < _threads.size(); i++)
        _threads[i]->join();
}

Search::~Search(){
    for (auto &thread : _threads)
        delete thread;
}