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

void FieldSearch::Search(SearchSettings ssettings){
    NormalizeMarkedTargets(ssettings);
    gmp::mpz_int initalelement = ssettings.targets[0].data[0];
    gmp::mpz_int s = (_f.getModuli()*(_f.getModuli()-1)+initalelement);
    gmp::mpz_int p = _f.getModuli();
    gmp::mpz_int _gx = gmp::powm(_f.getGenerator(), ssettings.index, _f.getModuli());
    //gmp::mpz_int _gx1 = gmp::powm(_f.getGenerator(), ssettings.index+1, _f.getModuli());
    gmp::mpz_int aprev = 0;
    std::vector<gmp::mpz_int> firstfound(26, 0);
    gmp::mpz_int foundcount = 0;
    for (gmp::mpz_int a(ssettings.a_offset); a < _f.getModuli(); a++){
        gmp::mpz_int aa = a*13+7;
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);

        SearchState searchstate{
            .searchsettings=ssettings,
            .fd=_f,
            .gx=_gx,
            .s=s
        };

        for (auto &action : Actions)
            action.act(searchstate);
        
        uint8_t check = (uint8_t)(_f.getElement(ssettings.index+1)%ssettings.printsettings.subfield);
        /*if (check != 0){
            std::cout << aa << std::endl;
            break;
        }*/
        if (!firstfound[check]){
            firstfound[check] = a;
            foundcount++;
        }
        
        //if (foundcount == 27)
        //    break;
    }
    for (int i = 0; i < firstfound.size(); i++)
        std::cout << (uint8_t)('A'+i) << ": " << firstfound[i] << ", ";
    std::cout << "Search Complete" << std::endl;
}