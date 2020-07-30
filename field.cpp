#include "field.h"

Field::Field(FieldParameters fieldparameters) : _g(fieldparameters.generator), _p(fieldparameters.modulo), _a(fieldparameters.coefficenta), _b(fieldparameters.coefficentb) {};

void Field::print(const PrintSettings &psettings) const{
    switch(psettings.printmode){
        case PrintSettings::PrintMode::Dec:
        printDec(psettings);break;
        case PrintSettings::PrintMode::Hex:
        printHex(psettings); break;
        case PrintSettings::PrintMode::Char:
        printChar(psettings);break;
    }
}

void Field::printDec(const PrintSettings &psettings) const{
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << ((getElement(i)%psettings.subfield)+psettings.post_offset) << psettings.separator;
    std::cout << (psettings.range==size()?"":"...") << std::endl;
}

void Field::printHex(const PrintSettings &psettings) const{
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << std::setfill(' ') << std::setw( 2 ) << std::hex  << ((getElement(i)%psettings.subfield)+psettings.post_offset) << psettings.separator;
    std::cout << (psettings.range==size()?"":"...") << std::dec << std::endl;
}

void Field::printChar(const PrintSettings &psettings) const{
    for (gmp::mpz_int i = psettings.offset; i < psettings.offset+psettings.range; i++)
        std::cout << (uint8_t)((getElement(i)%psettings.subfield)+psettings.post_offset) << psettings.separator;
    std::cout << (psettings.range==size()?"":"...")<< std::endl;
}

void Field::printElementFieldEquation(const gmp::mpz_int &index) const{
    std::cout << _a << " * " << _g << " ^ "<< index << " + " << _b << "\t";
}

void Field::printElementFieldEquationGXPrecomputed(const gmp::mpz_int &gx) const{
    std::cout << _a << " * " << gx << " + " << _b << "\t";
}

void Field::printGeneralFieldEquation() const{
    std::cout << _a << " * " << _g << "^x + " << _b << "\t";
}

bool Field::containsAt(const gmp::mpz_int &index, const std::vector<gmp::mpz_int> &elements,const gmp::mpz_int &subfield) const{
    bool match = true;
    for (gmp::mpz_int i = index; i < elements.size()+index; i++)
        if (elements[(size_t)(i-index)] != (getElement(i)%subfield))
            match = false;
    return match;
}
