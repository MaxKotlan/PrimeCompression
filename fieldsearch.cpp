#include "fieldsearch.h"
#include "actions.h"

void FieldSearch::NormalizeMarkedTargets(SearchSettings& s){
    for (auto &t : s.targets)
        if (t.normalize)
            NormalizeTarget(t, s.printsettings.post_offset);
}

void FieldSearch::NormalizeTarget(Target &t, gmp::mpz_int &post_offset){
    for (auto &e : t.data)
        e = e - post_offset;
}

void FieldSearch::Search(){
    SearchSettings conf_searchsettings = _conf.getSearchSettings();
    PrintSettings  conf_printsettings  = _conf.getPrintSettings();
    conf_searchsettings.printsettings  = conf_printsettings;
    gmp::mpz_int initalelement = ((conf_searchsettings.initalelementnormalize) ? (uint32_t)(conf_searchsettings.initalelement - 'A') : conf_searchsettings.initalelement);
    gmp::mpz_int s = (_f.getModuli()*(_f.getModuli()-1)+initalelement);
    gmp::mpz_int p = _f.getModuli();
    gmp::mpz_int _gx = gmp::powm(_f.getGenerator(), conf_searchsettings.index, _f.getModuli());
    for (gmp::mpz_int a(conf_searchsettings.a_offset); a < _f.getModuli(); a++){
        
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);

        SearchState searchstate{
            .searchsettings=conf_searchsettings,
            .fd=_f,
            .gx=_gx,
            .s=s
        };

        for (auto action: _conf.getActions())
            action->operator()(searchstate);

    }
    std::cout << "Search Complete" << std::endl;
}