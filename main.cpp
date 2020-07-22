#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "fieldsearch.h"

using namespace gmp;

void SearchLarge(){
    Field field({
        .generator=mpz_int("9421789245798175298217598251798512719825719825719887219857982157"),
        .moduli=mpz_int("4776913109852041418248056622882488319")
    });
    FieldSearch fs(field);
    fs.Search({
        .index=1,
        .pollingrate=1000000,
        .printmatches=true,
        .printnonmatches=false,
        .targets={
            Target{
                .data={ 'M', 'A', 'X', 'W', 'E', },
                .normalize=true,
                .halt=false
            },
            Target{
                .data={ 'M', 'A', 'X', 'W', 'E', 'L', 'L'},
                .normalize=true,
                .halt=true
            }
        },
        .printsettings={
            PrintSettings{
                .range=15,
                .offset=0,
                .post_offset='A',
                .subfield=26,
                .equationformat=PrintSettings::GX,
                .printmode=PrintSettings::PrintMode::Char   
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
    fs.Search({
        .index=0,
        .targets={
            Target{
                .data={7}
            }
        },
        .printsettings={
            PrintSettings{
                .post_offset='0',
                .printmode=PrintSettings::PrintMode::Char   
            }
        }
    });
}

int main(int argc, char** argv){
    SearchSmall();
    SearchLarge();
    return 0;
}