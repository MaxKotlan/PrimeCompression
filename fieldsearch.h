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
        uint32_t _g = 3;//3;
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
    uint32_t pollingrate = 10000000;
    uint32_t index = 0;
    uint32_t count = 0;
    _gx = powermod(_g, index+_fieldoffset, _p)%_r;//, _p)%_p;
    bool match = true;
    for (int s = 0; s < _p; s++){
        uint32_t solution = _p*s+(uint32_t)_searchfor->operator[](index);

        Result r;
        std::cout << "i: " << _gx-1 << "range: " << _gx << " " << solution << std::endl;
        for (uint32_t i = _gx-1; (i*_gx)%solution <= solution; i++){
            count++;
            r.a=i;
            r.b=solution-i*_gx;
            r.g = _gx;
            if (count%pollingrate==0)
            std::cout << i << ": " << r << ": ";

            match = true;
            for (uint32_t check = 0; check < _searchfor->size()+_fieldoffset; check++){
                uint32_t ch = (((r.a*powermod(_g, check, _p)+r.b)%_p)%_r);
                if (count%pollingrate==0)
                    std::cout << ch << " ";
                if (check >= _fieldoffset)
                    if (ch != _searchfor->operator[](check-_fieldoffset))
                        match = false;
            }
            if (count%pollingrate==0){
            for (uint32_t check = check < _searchfor->size()+_fieldoffset; check < 10; check++){
                uint32_t ch = (((r.a*powermod(_g, check, _p)+r.b)%_p)%_r);
                std::cout << ch << " ";
            }}
            if (count%pollingrate==0)
            std::cout << std::endl;
            if (match) {
                std::cout << "FOUND! ";
                std::cout << solution << " " << r.a << "*" << r.g << " + " << r.b << std::endl;
                for (uint32_t cc = 0; cc < 10; cc++)
                    std::cout << (uint8_t)(((r.a*powermod(_g, cc, _p)+r.b)%_p)%_r) << " ";
            }
            if (match) break;
        }
        if (match) break;
        //if (r.b > _p/2) break;
    }
}