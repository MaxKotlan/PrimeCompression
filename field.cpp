#include "field.h"

Field::Field(FieldParameters fieldparameters) : _g(fieldparameters.generator), _p(fieldparameters.moduli), _a(fieldparameters.coefficenta), _b(fieldparameters.coefficentb) {};

void Field::print(PrintSettings &psettings){
    if(psettings.range==0)
        psettings.range=size();
    switch(psettings.printmode){
        case PrintSettings::PrintMode::Dec:
        printDec(psettings);break;
        case PrintSettings::PrintMode::Hex:
        printHex(psettings); break;
        case PrintSettings::PrintMode::Char:
        printChar(psettings);break;
    }
}

void Field::printDec(PrintSettings &psettings){
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << ((getElement(i)%psettings.subfield)+psettings.post_offset) << " ";
    std::cout << (psettings.range==size()?"":"...") << std::endl;
}

void Field::printHex(PrintSettings &psettings){
    std::cout << std::hex << std::setw(2) << std::setfill('0');
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << std::setfill('0') << std::setw( 64 ) << std::hex  << ((getElement(i)%psettings.subfield)+psettings.post_offset) << " ";
    std::cout << (psettings.range==size()?"":"...") << std::dec << std::endl;
}

void Field::printChar(PrintSettings &psettings){
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << (uint8_t)((getElement(i)%psettings.subfield)+psettings.post_offset) << " ";
    std::cout << (psettings.range==size()?"":"...")<< std::endl;
}

void Field::printElementFieldEquation(gmp::mpz_int &index){
    std::cout << _a << " * " << _g << " ^ "<< index << " + " << _b << "\t";
}

void Field::printElementFieldEquationGXPrecomputed(gmp::mpz_int &gx){
    std::cout << _a << " * " << gx << " + " << _b << "\t";
}

void Field::printGeneralFieldEquation(){
    std::cout << _a << " * " << _g << "^x + " << _b << "\t";
}

bool Field::containsAt(gmp::mpz_int &index, std::vector<gmp::mpz_int> &elements){
    bool match = true;
    for (gmp::mpz_int i = index; i < elements.size()+index; i++)
        if (elements[(size_t)(i-index)] != (getElement(i)%26))
            match = false;
    return match;
}
