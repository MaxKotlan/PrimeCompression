#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "fieldsearch.h"
#include "actions.h"

using namespace gmp;

void SearchLarge(){
    Field field({
        .generator=mpz_int("42738974982347923857982357982357892357"),
        .moduli=/*(1 << 31)-1*/mpz_int("4776913109852041418248056622882488319")
    });
    FieldSearch fs(field);
    fs.Search({
        .a_offset=0,
        .index=0,
        .pollingrate=1000000,
        .printmatches=true,
        .printnonmatches=true,
        .targets={
            Target{
                .data={ 'M', 'A', 'X' },
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
    });
}

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
            }*/
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
}

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
    std::cout << Actions[0].id << std::endl;
    
    SearchSmall();
    //SearchMedium();
    //.predict(997, 12);

    SearchLarge();
    return 0;
}