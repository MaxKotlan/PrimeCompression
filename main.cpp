#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "fieldsearch.h"

using namespace gmp;

void SearchLarge(){
    Field field({
        .generator=3,//mpz_int("13999874411123227675658912014"),
        .moduli=97//mpz_int("4776913109852041418248056622882488319")
    });
    FieldSearch fs(field);
    /*
    fs.SetPrintSettings({
        .range=15,
        .offset=0,
        .post_offset='A',
        .subfield=26,
        .equationformat=PrintSettings::GX,
        .printmode=PrintSettings::PrintMode::Char   
    });*/

    fs.Search({
        .index=1,
        .pollingrate=1,
        .printnonmatches=true,
        .targets={
            Target{
                .data={ 'M', 'A' },
                .normalize=true,
                .halt=false
            },
            Target{
                .data={ 'M', 'A', 'X', 'W'},
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