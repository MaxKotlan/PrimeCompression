#include "fieldsearch.h"

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
    for (gmp::mpz_int a(0); a < _f.getModuli(); a++){
        _f.setA(a);
        gmp::mpz_int b = (s - _gx*a)%p;
        _f.setB(b);
        if (a%ssettings.pollingrate==0 && ssettings.printnonmatches){
            switch(ssettings.printsettings.equationformat) {
                case PrintSettings::EquationFormat::GX: _f.printElementFieldEquationGXPrecomputed(_gx); break; 
                case PrintSettings::GPowerX:            _f.printElementFieldEquation(ssettings.index); break;
            }
            _f.print(ssettings.printsettings);
        }
        for (Target &targ : ssettings.targets){
            if (_f.containsAt(ssettings.index, targ.data)){
                std::cout << "Found at: ";
                _f.printElementFieldEquation(ssettings.index);
                _f.print(ssettings.printsettings);
                std::cout << std::endl;
                if (targ.halt)
                    exit(0);
            }
        }
    }
    std::cout << "Search Complete" << std::endl;
}