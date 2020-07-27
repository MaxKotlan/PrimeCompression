#include <iostream>
#include <boost/multiprecision/gmp.hpp>
#include "fieldsearch.h"
#include "config.h"
#include "actions.h"

using namespace gmp;

int main(int argc, char** argv){
    Config conf("config.json");
    FieldSearch(conf).Search();
    return 0;
}