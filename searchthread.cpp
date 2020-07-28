#include "searchthread.h"
#include "actions.h"

void SearchThread::NormalizeMarkedTargets(SearchSettings& s){
    for (auto &t : s.targets)
        if (t.normalize)
            NormalizeTarget(t, s.printsettings.post_offset);
}

void SearchThread::NormalizeTarget(Target &t, gmp::mpz_int &post_offset){
    for (auto &e : t.data)
        e = e - post_offset;
}

void SearchThread::Search(uint64_t threadid, uint64_t threadcount){
    SearchSettings conf_searchsettings = _conf->getSearchSettings();
    PrintSettings  conf_printsettings  = _conf->getPrintSettings();
    conf_searchsettings.printsettings  = conf_printsettings;
    gmp::mpz_int initalelement = ((conf_searchsettings.initalelementnormalize) ? (uint32_t)(conf_searchsettings.initalelement - 'A') : conf_searchsettings.initalelement);

    SearchState state{
        .fd=_f,
        .gx=gmp::powm(_f.getGenerator(), conf_searchsettings.index, _f.getModuli()),
        .s=(_f.getModuli()*(_f.getModuli()-1)+initalelement)
    };
    gmp::mpz_int p = _f.getModuli();
    for (gmp::mpz_int a(conf_searchsettings.a_offset+threadid); a < _f.getModuli(); a+=threadcount){
        _f.setA(a);
        gmp::mpz_int b = (state.s - state.gx*a)%p;
        _f.setB(b);

        for (auto action: _conf->getActions())
            action->operator()(state);

    }
    std::cout << "Search Complete" << std::endl;
}