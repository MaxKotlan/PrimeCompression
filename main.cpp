#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "fieldsearch.h"
#include "config.h"
#include "actions.h"

using namespace gmp;

void SearchLarge(){
    Config conf("config.json");
    Field field({
        .generator=mpz_int("27385783295798237589235798273598289357892357329857"),
        .moduli=mpz_int("43143988327398957279342419750374600193")//mpz_int("8683317618811886495518194401279999999")//103843//7919//((1 << 31) -1)
    });
    FieldSearch fs(field);
    fs.Search({
        .a_offset=0,
        .index=3,
        .pollingrate=1000000,
        .printmatches=true,
        .printnonmatches=true,
        .targets={
            Target{
                .data={ 'M', 'A', 'X', 'W'},
                .normalize=true,
                .halt=false
            }/*,
            Target{
                .data={ 'M', 'A', 'X', 'W', 'E', 'L', 'L'},
                .normalize=true,
                .halt=true
            }*/
        },
        .printsettings={
            PrintSettings{
                .range=15,
                .offset=0,
                //.offset=mpz_int("25937898235789327589327523895789532729875398"),
                .post_offset='A',
                .subfield=26,
                .equationformat=PrintSettings::GX,
                .printmode=PrintSettings::PrintMode::Char   
            }
        }
    }, conf);
}
/*
void SearchMedium(){
    Field field({
        .generator=3,//mpz_int("94217892"),
        .moduli=97//mpz_int("4776913109852041418248056622882488319")
    });
    FieldSearch fs(field);
    fs.Search({
        .index=0,
        .pollingrate=1,
        .printmatches=false,
        .printnonmatches=true,
        .targets={
            Target{
                .data={ 'M', 'O' },
                .normalize=true,
                .halt=false
            }/*,
            Target{
                .data={ 'M', 'A', 'X', 'W', 'E', 'L', 'L'},
                .normalize=true,
                .halt=true
            }
        },
        .printsettings={
            PrintSettings{
                .range=30,
                .offset=0,
                //.offset=mpz_int("25937898235789327589327523895789532729875398"),
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
        .index=2,
        .targets={
            Target{
                .data={7}
            }
        },
        .printsettings={
            PrintSettings{
                .printmode=PrintSettings::PrintMode::Hex   
            }
        }
    });
}*/

mpz_int mod(mpz_int a, mpz_int b){
    mpz_int c = a%b;
    if (c < 0) return b-c;
    return c;
}

mpz_int func(mpz_int p, mpz_int e1, mpz_int e2){
    mpz_int a = ((((p+1)/2)*(e2-e1))%p)%(p-e1-1);
    if (a < 0) return (p-e1-1) - a;
    return a;
}

void predict(mpz_int p, mpz_int e1){
    for (int i = 0; i < 26; i++)
        std::cout << (uint8_t)(i+'A') << ": " << func(p, e1, i) << ", ";
}

int main(int argc, char** argv){
    //Config("config.json");
    //std::cout << Actions[0].id << std::endl;
    //SearchSmall();
    //SearchMedium();
    //.predict(997, 12);

    SearchLarge();
    return 0;
}