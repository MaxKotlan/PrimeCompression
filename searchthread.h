#pragma once
#include "field.h"
#include "searchsettings.h"
#include "config.h"

class SearchThread{
    public:
        SearchThread(Config* conf) : _conf(conf), _f(conf->getFieldParameters()){}
        void Search(uint64_t threadid, uint64_t threadcount);

    private:
        Config* _conf;
        Field _f;
};