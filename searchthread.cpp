#include "searchthread.h"
#include "actions.h"

void SearchThread::Search(uint64_t threadid, uint64_t threadcount){
    SearchSettings conf_searchsettings = _conf->getSearchSettings();
    PrintSettings  conf_printsettings  = _conf->getPrintSettings();

    gmp::mpz_int initalelement = ((conf_searchsettings.initalelementnormalize) ? (uint32_t)(conf_searchsettings.initalelement - 'A') : conf_searchsettings.initalelement);

    SearchState state{
        .fd=_f,
        .gx=gmp::powm(_f.getGenerator(), conf_searchsettings.index, _f.getModulo()),
        .s=(_f.getModulo()*(_f.getModulo()-1)+initalelement)
    };
    gmp::mpz_int p = _f.getModulo();
    for (gmp::mpz_int a(conf_searchsettings.a_offset+threadid); a < _f.getModulo() && a < conf_searchsettings.a_range; a+=threadcount){
        _f.setA(a);
        gmp::mpz_int b = (state.s - state.gx*a)%p;
        _f.setB(b);

        for (auto action: _conf->getActions())
            action->operator()(state);

    }
    std::cout << "Search Complete" << std::endl;
}