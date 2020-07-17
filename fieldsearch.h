#pragma once
#include "fast_integer_exponentiation.h"
#include "printallsums.h"

class FieldSearch{
    public:
        FieldSearch(std::vector<uint8_t>* searchfor);
        void search();

    private:
        uint32_t _p = 2147483647;
        uint32_t _r = 256;
        uint32_t _g = 5;
        uint32_t _gx;
        uint32_t _fieldoffset=1;
        uint32_t printdepth = 10;
        std::vector<uint8_t>* _searchfor;
        std::vector<uint8_t>  _field;
};

FieldSearch::FieldSearch(std::vector<uint8_t>* searchfor): _searchfor(searchfor) {
    search();
}

void FieldSearch::search(){
    uint32_t index = 0;
    _gx = power(_g, index+_fieldoffset);//, _p)%_p;

    bool match = true;
    for (int s = 0; s < 10; s++){
        uint32_t solution = _p*s+(uint32_t)_searchfor->operator[](index);

        Result r;
        for (uint32_t i = _gx-1; i*_gx <= solution; i++){
            r.a=i;
            r.b=solution-i*_gx;
            r.g = _gx;
            std::cout << i << ": " << r << ": ";

            match = true;
            for (int check = 0; check < _searchfor->size()+_fieldoffset; check++){
                uint8_t ch = (((r.a*powermod(_g, check, _p)+r.b)%_p)%_r);
                std::cout << ch << " ";
                if (check >= _fieldoffset)
                    if (ch != _searchfor->operator[](check-_fieldoffset))
                        match = false;
            }
            std::cout << std::endl;
            if (match) {
                std::cout << "FOUND!";
            }
            if (match) break;
        }
        if (match) break;
        //if (r.b > _p/2) break;
    }
}