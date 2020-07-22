#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "fieldsearch.h"

using namespace gmp;

void SearchLarge(){
    Field field({
        .generator=mpz_int("13999874411123227675658912014"),
        .moduli=mpz_int("4776913109852041418248056622882488319")
    });
    FieldSearch fs(field);
    fs.SetPrintSettings({
        .range=15,
        .offset=0,
        .post_offset='A',
        .subfield=26,
        .printmode=PrintSettings::PrintMode::Char   
    });

    fs.Search({
        .targets={
            Target{
                .data={ 'C', 'L', 'A', 'Y', 'J'},
                .normalize=true,
            },
            Target{
                .data={ 'C', 'L', 'A', 'Y', 'J', 'A', 'M', 'E', 'S'},
                .normalize=true,
                .halt=false
            }
        }
    });
}

void SearchSmall(){
    Field field({
        .generator=3,
        .moduli=17
    });
    FieldSearch fs(field);
    fs.SetPrintSettings({
        .post_offset='0',
        .printmode=PrintSettings::PrintMode::Char   
    });
    fs.Search({
        .targets={
            Target{
                .data={7}
            }
        }
    });
}

int main(int argc, char** argv){
    SearchSmall();
    SearchLarge();
    return 0;
}