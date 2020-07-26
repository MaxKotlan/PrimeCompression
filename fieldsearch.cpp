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

void FieldSearch::Search(SearchSettings ssettings, Config& conf){
    NormalizeMarkedTargets(ssettings);
    gmp::mpz_int initalelement = ssettings.targets[0].data[0];
    gmp::mpz_int s = (_f.getModuli()*(_f.getModuli()-1)+initalelement);
    gmp::mpz_int p = _f.getModuli();
    gmp::mpz_int _gx = gmp::powm(_f.getGenerator(), ssettings.index, _f.getModuli());
    for (gmp::mpz_int a(ssettings.a_offset); a < _f.getModuli(); a++){
        
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);

        SearchState searchstate{
            .searchsettings=ssettings,
            .fd=_f,
            .gx=_gx,
            .s=s
        };

        for (auto action: conf._actions)
            action->operator()(searchstate);

        /*Action* ar;
        Print p;
        ar = &p;
        (*ar)(searchstate);*/
        //p(searchstate);
        /*
        for (auto &action : Actions)
            action.act(searchstate, action);
        */
    }
    std::cout << "Search Complete" << std::endl;
}